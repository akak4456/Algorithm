//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int V, adj[500][500];
int delay[500];
int W[500][500];
void solve() {
	vector<pair<int, int> > order;
	for (int i = 0; i < V; i++)
		order.push_back(make_pair(delay[i], i));
	sort(order.begin(), order.end());
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			if (i == j)
				W[i][j] = 0;
			else
				W[i][j] = adj[i][j];
	int ret = INF;
	for (int k = 0; k < V; k++) {
		int w = order[k].second;
		for(int i=0;i<V;i++)
			for (int j = 0; j < V; j++) {
				adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
				W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
			}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	int E;
	cin >> V >> E;
	for (int i = 0; i < V; i++)
		cin >> delay[i];
	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; j++)
			adj[i][j] = INF;
	for (int i = 0; i < E; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a-1][b-1] = d;
		adj[b-1][a-1] = d;
	}
	solve();
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << W[a-1][b-1] << endl;
	}
}