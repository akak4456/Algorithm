//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_V = 101;
const int INF = 987654321;
int n;
int m;
int adj[MAX_V][MAX_V];
void floyd() {
	for (int i = 1; i <= n; i++) adj[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < MAX_V; i++)
		for (int j = 0; j < MAX_V; j++)
			adj[i][j] = INF;
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a][b] = min(adj[a][b],d);
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adj[i][j] == INF) {
				cout << "0 ";
			}
			else {
				cout << adj[i][j] << " ";
			}
		}
		cout << endl;
	}
}