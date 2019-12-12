//result:맞았습니다!!
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
	bool cycle = false;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			for (auto& p : adj[j]) {
				int nexT = p.first, d = p.second;
				if (upper[j] != INF && upper[nexT] > upper[j] + d) {
					upper[nexT] = upper[j] + d;
					if (i == N - 1) cycle = true;
				}
			}
		}
	}
	if (cycle) upper.clear();
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
			if (ans[i] == INF) {
				cout << "-1\n";
			}
			else {
				cout << ans[i] << '\n';
			}
		}
	}
}