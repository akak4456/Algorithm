﻿//result:틀렸습니다
/*
1

5 5 4

1 2 2 1

2 3 2 1

3 5 2 1

1 3 1 5
답 6
출력 Poor KCM
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_V = 101;
const int INF = 987654321;
int T;
int N, M, K;
int adj[MAX_V][MAX_V];
int cost[MAX_V][MAX_V];
int minDist = INF;
bool visited[MAX_V];
vector<int> nexT[MAX_V];
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
void findMinDist(int src,int money,int dist) {
	if (cost[src][N] <= money) {
		dist += adj[src][N];
		if (dist < minDist) {
			minDist = dist;
		}
		return;
	}
	for (int i = 0; i < nexT[src].size(); i++) {
		int nextIdx = nexT[src][i];
		if (!visited[nextIdx]&&money - cost[src][nextIdx] >= 0) {
			visited[nextIdx] = true;
			findMinDist(nextIdx, money - cost[src][nextIdx], dist + adj[src][nextIdx]);
			visited[nextIdx] = false;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		minDist = INF;
		for (int i = 0; i < MAX_V; i++) {
			nexT[i].clear();
			visited[i] = false;
			for (int j = 0; j < MAX_V; j++) {
				adj[i][j] = INF;
				cost[i][j] = INF;
			}
		}
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u][v] = d;
			cost[u][v] = c;
			nexT[u].push_back(v);
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
		findMinDist(1, M, 0);
		if (minDist == INF) {
			cout << "Poor KCM\n";
		}
		else {
			cout << minDist << '\n';
		}
	}
}