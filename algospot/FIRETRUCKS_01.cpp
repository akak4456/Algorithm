//result:정답
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 987654321;
const int MAX_V = 1001;
int V, E;
vector<int> fire;
vector<int> fireTruck;
vector<int> timefire;
vector<pair<int, int> > adj[MAX_V];
vector<int> dijkstra(int src) {
	vector<int> dist(V+1, MAX);
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
int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		int n, m;
		cin >> V >> E >> n >> m;
		fire.clear();
		fireTruck.clear();
		timefire = vector<int>(n, MAX);
		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();
		for (int i = 0; i < E; i++) {
			int a, b, t;
			cin >> a >> b >> t;
			adj[a].push_back(make_pair(b, t));
			adj[b].push_back(make_pair(a, t));
		}
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			fire.push_back(t);
		}
		for (int i = 0; i < m; i++) {
			int t;
			cin >> t;
			fireTruck.push_back(t);
		}
		for (int i = 0; i < m; i++) {
			vector<int> ans = dijkstra(fireTruck[i]);
			for (int idx = 0; idx < n; idx++) {
				if (timefire[idx] > ans[fire[idx]]) {
					timefire[idx] = ans[fire[idx]];
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += timefire[i];
		}
		cout << sum << endl;
	}
}