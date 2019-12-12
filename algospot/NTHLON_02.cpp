//result:정답
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V;
vector<pair<int, int> > adj[402];
const int START = 401;
int vertex(int delta) {
	return delta + 200;
}
const int MAX = 987654321;
vector<int> dijkstra(int src) {
	vector<int> dist(V, MAX);
	dist[src] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}
int solve(const vector<int>& a, const vector<int>& b) {
	V = 402;
	for (int i = 0; i < V; i++) adj[i].clear();
	for (int i = 0; i < a.size(); i++) {
		int delta = a[i] - b[i];
		adj[START].push_back(make_pair(vertex(delta), a[i]));
	}
	for (int delta = -200; delta <= 200; delta++) {
		for (int i = 0; i < a.size(); i++) {
			int next = delta + a[i] - b[i];
			if (abs(next) > 200) continue;
			adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
		}
	}
	vector<int> shortest = dijkstra(START);
	int ret = shortest[vertex(0)];
	if (ret == MAX) return -1;
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		int m;
		cin >> m;
		vector<int> a(m);
		vector<int> b(m);
		for (int i = 0; i < m; i++) {
			cin >> a[i] >> b[i];
		}
		int ans = solve(a, b);
		if (ans == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;;
	}
}