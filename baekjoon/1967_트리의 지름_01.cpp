//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int V;
vector<pair<int,int> > tree[100001];//연결된 노드 가중치
int dis[100001];
bool visited[100001];
void dfs(int node, int dist) {
	visited[node] = true;
	for (int i = 0; i < tree[node].size(); i++) {
		int nextNode = tree[node][i].first;
		int nextCost = tree[node][i].second;
		if (!visited[nextNode]) {
			dis[nextNode] = dist + nextCost;
			dfs(nextNode, dist + nextCost);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V;
	for (int i = 1; i <= V - 1; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		tree[a].push_back(make_pair(b, t));
		tree[b].push_back(make_pair(a, t));
	}
	dfs(1, 0);
	int ans = -1, start;
	for (int i = 1; i <= V; i++) {
		visited[i] = false;
		if (ans < dis[i]) {
			start = i;
			ans = dis[i];
		}
	}
	dfs(start, 0);
	for (int i = 1; i <= V; i++) {
		if (ans < dis[i]) {
			ans = dis[i];
		}
	}
	cout << ans << '\n';
}