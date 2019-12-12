//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;
struct node {
	int pos, cost, time;
	bool operator < (const node& p) const {
		if (this->time == p.time) return this->cost > p.cost;
		return this->time > p.time;
	}
};
int T;
int N, M, K;
int dp[101][10001];
vector<node> adj[101];
priority_queue<node> q;
int dijkstra() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++)dp[i][j] = INF;
	}
	q = {};
	q.push({ 0,0,0 });
	dp[0][0] = 0;
	while (!q.empty()) {
		node top = q.top();
		q.pop();
		int cost = top.cost;
		int dtime = top.time;
		int pos = top.pos;
		if (pos == N - 1) break;
		if (dp[pos][cost] < dtime) continue;
		dp[pos][cost] = dtime;
		for (int i = 0; i < adj[pos].size(); i++) {
			node& next = adj[pos][i];

			if (cost + next.cost > M) continue;
			if (dp[next.pos][cost + next.cost] <= dtime + next.time) continue;
			node t;
			t.pos = next.pos;
			t.cost = cost + next.cost;
			t.time = dtime + next.time;
			q.push(t);
			dp[next.pos][cost + next.cost] = dtime + next.time;
		}
	}
	int ret = INF;
	for (int i = 0; i <= M; i++)
		ret = min(ret, dp[N - 1][i]);
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++)
			adj[i].clear();
		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			adj[u-1].push_back({ v-1,c,d });
		}
		int r = dijkstra();
		if (r < INF) cout << r << '\n';
		else cout <<"Poor KCM\n";
	}
}