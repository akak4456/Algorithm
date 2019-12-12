//result:오답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int V, W;
const int MAX_V = 100;
const int INF = 987654321;
vector<pair<int, int> > adj[MAX_V];
bool reachable[MAX_V][MAX_V];
int bellman2(int src, int target) {
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				reachable[i][j] |= reachable[i][k] && reachable[k][j];
	vector<int> upper(V, INF);
	upper[src] = 0;
	for (int iter = 0; iter < V - 1; iter++) {
		for (int here = 0; here < V; here++) {
			for (int i = 0; i < adj[here].size(); i++) {
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				upper[there] = min(upper[there], upper[here] + cost);
			}
		}
	}
	for (int here = 0; here < V; here++) {
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int cost = adj[here][i].second;

			if (upper[here] + cost < upper[there]) {
				if (reachable[src][here] && reachable[here][target])
					return INF;
			}
		}
	}
	if (upper[1] >= INF - 98765432)
		return -INF;
	return upper[target];
}
int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();
		for (int i = 0; i < MAX_V; i++)
			for (int j = 0; j < MAX_V; j++)
				reachable[i][j] = false;
		for (int i = 0; i < V; i++)
			reachable[i][i] = true;
		cin >> V >> W;
		for (int i = 0; i < W; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back(make_pair(b, d));
			reachable[a][b] = true;
		}
		int ans1 = bellman2(0, 1);
		if (ans1 == -INF) {
			cout << "UNREACHABLE" << endl;
			continue;
		}
		if (ans1 == INF) {
			cout << "INFINITY ";
		}
		else {
			cout << ans1 << ' ';
		}
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				adj[i][j].second *= -1;
			}
		}
		int ans2 = bellman2(0, 1);
		if (ans2 == INF) {
			cout << "INFINiTY" << endl;
		}
		else {
			cout << -ans2 << endl;
		}
	}
}