//result:틀렸습니다
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_N = 32000 + 1;
int N, M;
vector<int> adj[MAX_N];
stack<int> st;
bool visited[MAX_N];
int indegree[MAX_N];
void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		int nxt = adj[v][i];
		if (!visited[nxt])
			dfs(nxt);
	}
	st.push(v);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		adj[t1].push_back(t2);
		indegree[t2]++;
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			dfs(i);
			while (!st.empty()) {
				cout << st.top() << ' ';
				st.pop();
			}
		}
	}
	cout << '\n';
}