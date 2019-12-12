//result:맞았습니다!!
#include <iostream>
#include <vector>
using namespace std;
const int MAX_V = 501;
const int INF = 987654321;
int TC;
int N, M, W;
vector<pair<int, int> > adj[MAX_V];
bool bellmanFord() {
	vector<int> upper(N + 1, INF);
	upper[1] = 0;
	bool updated = false;
	for (int iter = 0; iter < N; iter++) {
		updated = false;
		for (int here = 1; here <= N; here++) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				if (upper[here] != INF && upper[there] > upper[here] + cost) {
					updated = true;
					upper[there] = upper[here] + cost;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) return false;
	return true;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> TC;
	while (TC--) {
		cin >> N >> M >> W;
		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();
		for (int i = 0; i < M; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(e, t));
			adj[e].push_back(make_pair(s, t));
		}
		for (int i = 0; i < W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			adj[s].push_back(make_pair(e, -t));
		}
		if (bellmanFord()) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}
	}
}