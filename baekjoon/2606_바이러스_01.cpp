//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> nextNode[1001];
int N, M;
bool visited[1001];
int cnt = 0;
void dfs(int v) {
	cnt++;
	visited[v] = true;
	for (int i = 0; i < nextNode[v].size(); i++) {
		if (visited[nextNode[v][i]] == false) {
			visited[nextNode[v][i]] = true;
			dfs(nextNode[v][i]);
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		nextNode[t1].push_back(t2);
		nextNode[t2].push_back(t1);
	}
	for (int i = 1; i <= N; i++) {
		sort(nextNode[i].begin(), nextNode[i].end());
	}
	for (int i = 0; i <= 1000; i++)
		visited[i] = false;
	dfs(1);
	cout << cnt - 1 << '\n';
}