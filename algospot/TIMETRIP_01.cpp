//result:오답
#include <iostream>
#include <vector>
using namespace std;
int V, W;
const int MAX_V = 100;
const int INF = 987654321;
vector<pair<int, int> > adj[MAX_V];
vector<int> bellmanFord(int src) {
	vector<int> upper(V, INF);
	upper[src] = 0;
	bool updated;
	for (int iter = 0; iter < V; iter++) {
		updated = false;
		for (int here = 0; here < V; here++) {
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
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();
		cin >> V >> W;
		for (int i = 0; i < W; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back(make_pair(b, d));
		}
		vector<int> ans = bellmanFord(0);
		int ans1 = INF, ans2 = INF;
		if(!ans.empty())
		ans1 = ans[1];
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				adj[i][j].second *= -1;
			}
		}
		ans = bellmanFord(0);
		if (!ans.empty())
			ans2 = ans[1]*-1;
		if (ans1 == INF && ans2 == -INF)
			cout << "UNREACHABLE";
		else {
			if (ans1 == INF)
				cout << "INFINITY";
			else
				cout << ans1;
			cout << ' ';
			if (ans2 == INF)
				cout << "INFINITY";
			else
				cout << ans2;
			cout << endl;
		}
		//cout << ans1 << ' ' << ans2 << endl;
	}
}