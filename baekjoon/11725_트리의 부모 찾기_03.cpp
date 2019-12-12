//result:맞았습니다!!
#include <iostream>
#include <vector>
using namespace std;
int N;
int parent[100001];
vector<int> tree[100001];
bool visited[100001];
void dfs(int node) {
	visited[node] = true;
	for (int i = 0; i < tree[node].size(); i++) {
		int nextNode = tree[node][i];
		if (!visited[nextNode]) {
			parent[nextNode] = node;
			dfs(nextNode);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	parent[1] = -1;
	for (int i = 1; i <= N-1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}