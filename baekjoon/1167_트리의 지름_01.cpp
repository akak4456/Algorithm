//result:틀렸습니다
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int V;
vector<pair<int,int> > tree[100001];//연결된 노드 가중치
bool visited[100001];
int best = -1;
void dfs(int node, int dist) {
	visited[node] = true;
	for (int i = 0; i < tree[node].size(); i++) {
		int nextNode = tree[node][i].first;
		int nextCost = tree[node][i].second;
		if (!visited[nextNode]) {
			if (tree[nextNode].size() == 1) {
				visited[nextNode] = true;
				if (best < dist + nextCost) {
					best = dist + nextCost;
				}
			}
			else {
				dfs(nextNode, dist + nextCost);
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V;
	for (int i = 1; i <= V; i++) {
		int a;
		cin >> a;
		int b, t;
		while (true) {
			cin >> b;
			if (b == -1)
				break;
			cin >> t;
			tree[a].push_back(make_pair(b, t));
		}
	}
	int terminalIdx = -1;
	for (int i = 1; i <= V; i++) {
		if (tree[i].size() == 1) {
			terminalIdx = i;
			break;
		}
	}
	dfs(terminalIdx, 0);
	cout << best << '\n';
}