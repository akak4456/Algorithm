//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> nextNode[1001];
int N, M, V;
bool visited[1001];
void dfs(int v) {
	cout << v << ' ';
	visited[v] = true;
	for (int i = 0; i < nextNode[v].size(); i++) {
		if (visited[nextNode[v][i]] == false) {
			visited[nextNode[v][i]] = true;
			dfs(nextNode[v][i]);
		}
	}
}
void bfs(int v) {
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int t = q.front();
		visited[t] = true;
		q.pop();
		cout << t << ' ';
		for (int i = 0; i < nextNode[t].size(); i++) {
			if (visited[nextNode[t][i]] == false) {
				visited[nextNode[t][i]] = true;
				q.push(nextNode[t][i]);
			}
		}
	}
}
int main() {
	cin >> N >> M >> V;
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
	dfs(V);
	for (int i = 0; i <= 1000; i++)
		visited[i] = false;
	cout << '\n';
	bfs(V);
}