//result:시간 초과
/*
a에서 b로 연결된게 여러개일수 있다.
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
vector<pair<int,pair<int,int>>> nexT[MAX_V];
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
	//cout << src << ' '<<money <<' '<< dist << endl;
	if (dist >= minDist || dist > 10000) {
		return;
	}
	if (cost[src][N] <= money) {
		//dist += adj[src][N];
		if (dist+adj[src][N] < minDist) {
			minDist = dist+adj[src][N];
		}
		return;
	}
	for (int i = 0; i < nexT[src].size(); i++) {
		int nextIdx = nexT[src][i].first;
		if (!visited[nextIdx]&&money - nexT[src][i].second.first >= 0) {
			//cout << "src:" << src << " next:" << nextIdx<< endl;
			visited[nextIdx] = true;
			findMinDist(nextIdx, money - nexT[src][i].second.first, dist + nexT[src][i].second.second);
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
			if (adj[u][v] > d) {
				adj[u][v] = d;
				cost[u][v] = c;
			}
			else if (adj[u][v] == d && cost[u][v] > c) {
				cost[u][v] = c;
			}
			nexT[u].push_back(make_pair(v,make_pair(c,d)));
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