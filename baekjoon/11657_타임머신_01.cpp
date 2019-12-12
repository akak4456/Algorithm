//result:틀렸습니다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_V = 501;
const int INF = 987654321;
int N, M;
vector<pair<int, int> > adj[MAX_V];
vector<int> bellmanFord(int src) {
	vector<int> upper(N+1, INF);
	upper[src] = 0;
	bool updated;
	for (int iter = 0; iter < N; iter++) {
		updated = false;
		for (int here = 1; here <= N; here++) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;

				if (upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a].push_back(make_pair(b, d));
	}
	vector<int> ans = bellmanFord(1);
	if (ans.empty()) {
		cout << "-1\n";
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (ans[i] > INF - 60000000) {
				cout << "-1\n";
			}
			else {
				cout << ans[i] << '\n';
			}
		}
	}
}