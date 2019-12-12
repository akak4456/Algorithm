//result:틀렸습니다
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_V = 101;
const int INF = 987654321;
int T;
int N, M, K;
int adj[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];
int minDist = INF;
void floyd() {
	for (int i = 1; i <= N; i++) {
		adj[i][i] = 0;
		cost[i][i] = 0;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) {
				if (adj[i][j] > adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
}
void findMinDist(int src, int money,int dist) {
	if (src == N) {
		if (dist < minDist) {
			minDist = dist;
		}
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (src == i) {
			continue;
		}
		if (money - cost[src][i] >= 0) {
			findMinDist(i, money - cost[src][i],dist+adj[src][i]);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		minDist = INF;
		for (int i = 0; i < MAX_V; i++)
			for (int j = 0; j < MAX_V; j++) {
				adj[i][j] = INF;
				cost[i][j] = INF;
			}
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u][v] = d;
			cost[u][v] = c;
		}
		floyd();
		/*
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << adj[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << cost[i][j] << ' ';
			}
			cout << endl;
		}
		*/
		findMinDist(1, M,0);
		if (minDist == INF) {
			cout << "Poor KCM\n";
		}
		else {
			cout << minDist << '\n';
		}
	}
}