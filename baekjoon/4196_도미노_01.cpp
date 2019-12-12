//result:틀렸습니다
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_V = 100000 + 1;
vector<vector<int> > vt;
bool visited[MAX_V];
int T;
int N, M;
int indegree[MAX_V];
stack<int> st;
void dfs(int here) {
	visited[here] = true;
	for (int there : vt[here]) {
		if (!visited[there]) {
			indegree[there]--;
			if (indegree[there] == 0) {
				st.push(there);
			}
			dfs(there);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		memset(visited, false, sizeof(visited));
		vt.clear();
		cin >> N >> M;
		vt.resize(N + 1);
		for (int i = 0; i < M; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			vt[t1].push_back(t2);
			indegree[t2]++;
		}
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				st.push(i);
			}
		}
		int cnt = 0;
		while (!st.empty()) {
			int tmp = st.top();
			st.pop();
			if (!visited[tmp]) {
				cnt++;
				dfs(tmp);
			}
		}
		cout << cnt << '\n';
	}
}