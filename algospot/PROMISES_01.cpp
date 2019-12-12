//result:시간초과
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_V = 200;
const int INF = 987654321;
int V;
int M, N;
int adj[MAX_V][MAX_V];
void floyd() {
	for (int i = 0; i < V; i++) adj[i][i] = 0;
	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		cin >> V >> M >> N;
		for (int i = 0; i < MAX_V; i++)
			for (int j = 0; j < MAX_V; j++)
				adj[i][j] = INF;
		for (int i = 0; i < M; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a][b] = d;
			adj[b][a] = d;
		}
		floyd();
		int uselessCount = 0;
		for (int i = 0; i < N; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			int prevCost = adj[a][b];
			adj[a][b] = d;
			adj[b][a] = d;
			floyd();
			if (adj[a][b] >= prevCost) {
				uselessCount++;
			}
		}
		cout << uselessCount << endl;
	}
}