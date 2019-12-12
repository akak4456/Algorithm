//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_V = 401;
int n, m;
int adj[MAX_V][MAX_V];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < MAX_V; i++)
		for (int j = 0; j < MAX_V; j++)
			adj[i][j] = INF;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a][b] = d;
	}
	for (int i = 1; i <= n; i++) adj[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << adj[i][j] << ' ';
		}
		cout << endl;
	}
	*/
	int minDist = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (adj[i][j] + adj[j][k] + adj[k][i] > 0 && adj[i][j] + adj[j][k] + adj[k][i] < minDist) {
					minDist = adj[i][j] + adj[j][k] + adj[k][i];
				}
			}
		}
	}
	if (minDist == INF) {
		cout << "-1\n";
	}
	else {
		cout << minDist << '\n';
	}
}