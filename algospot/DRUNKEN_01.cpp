//result:오답
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int V, E;
const int INF = 987654321;
const int MAX_V = 500;
int adj[MAX_V][MAX_V];
int newAdj[MAX_V][MAX_V];
int via[MAX_V][MAX_V];
int consume[MAX_V];
void floyd() {
	for (int i = 0; i < V; i++)adj[i][i] = 0;
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					via[i][j] = k;
					adj[i][j] = adj[i][k] + adj[k][j];
				}
}
/*
void reconstruct(int u, int v, vector<int>& path) {
	if (via[u][v] == -1) {
		path.push_back(v);
		if (u != v) path.push_back(v);
	}
	else {
		int w = via[u][v];
		reconstruct(u, w, path);
		path.pop_back();
		reconstruct(w, v, path);
	}
}
*/
void reconstruct(int start, int end,int u, int v, int& best) {
	if (via[u][v] == -1) {
		if (u != start) {
			best = max(consume[u], best);
		}
		if (v != end) {
			best = max(consume[v], best);
		}
		//best = max(max(consume[u], best), consume[v]);
	}
	else {
		int w = via[u][v];
		reconstruct(start,end,u, w, best);
		reconstruct(start,end,w, v, best);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 0; i < V; i++) {
		cin >> consume[i];
	}
	for (int i = 0; i < MAX_V; i++)
		for (int j = 0; j < MAX_V; j++) {
			adj[i][j] = INF;
			via[i][j] = -1;
		}
	for (int i = 0; i < E; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a-1][b-1] = d;
		adj[b-1][a-1] = d;
	}
	floyd();
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << adj[i][j] << ' ';
		cout << endl;
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			int best = -1;
			reconstruct(i,j,i, j, best);
			newAdj[i][j] = adj[i][j];
			if (best >= 0)
				newAdj[i][j] += best;
		}
	}
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << newAdj[i][j] << ' ';
		cout << endl;
	}
	int t;
	cin >> t;
	while (t--) {
		int start, end;
		cin >> start >> end;
		int ans = newAdj[start][end];
		cout << ans << endl;
	}
}