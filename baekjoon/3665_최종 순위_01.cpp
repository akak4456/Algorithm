//result:틀렸습니다
#include <iostream>
#include <stack>
using namespace std;
const int MAX_N = 500 + 1;
bool adj[MAX_N][MAX_N];
int T;
int N,M;
bool visited[MAX_N],finish[MAX_N];
int order[MAX_N];
int cycle;
stack<int> st;
void dfs(int here) {
	//cout << here << '\n';
	visited[here] = true;
	for (int i = 1; i <= N; i++) {
		if (adj[here][i]) {
			if (!visited[i]) {
				dfs(i);
			}
			else if (!finish[i]) {
				cycle = 1;
			}
		}
		
	}
	finish[here] = true;
	st.push(here);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) {
				adj[i][j] = false;
			}
		}
		for (int i = 0; i < MAX_N; i++) {
			visited[i] = false;
			finish[i] = false;
		}
		cycle = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> order[i];
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				adj[order[i]][order[j]] = true;
			}
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			if (adj[t1][t2]) {
				adj[t1][t2] = false;
				adj[t2][t1] = true;
			}
			else {
				adj[t2][t1] = false;
				adj[t1][t2] = true;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i])
				dfs(i);
		}
		bool isCan = true;
		for (int i = 1; i <= N; i++) {
			if (!visited[i])
				isCan = false;
		}
		if (!isCan) {
			cout << "?\n";
		}else if (cycle == 1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			while (!st.empty()) {
				cout << st.top() << ' ';
				st.pop();
			}
			cout << '\n';
		}
	}
}