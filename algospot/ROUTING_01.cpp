//result:컴파일 실패
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 10000;
const int MAX = 987654321;
int V;
vector<pair<int, double> > adj[MAX_V];
vector<double> dijkstra(int src) {
	vector<double> dist(V, MAX);
	dist[src] = 1;
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<> >pq;
	pq.push(make_pair(1, src));
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			double nextDist = cost * adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(nextDist, there));
			}
		}
	}
	return dist;
}
int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		int m;
		cin >> V >> m;
		for (int i = 0; i < m; i++) {
			int t1, t2;
			double t3;
			cin >> t1 >> t2 >> t3;
			adj[t1].push_back(make_pair(t2, t3));
		}
		vector<double> ans = dijkstra(0);
		cout << ans[V - 1] << endl;
	}
}