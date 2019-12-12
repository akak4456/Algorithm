//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_V = 10000 + 1;
vector<vector<int> > vt;
vector<vector<int> > rvt;
vector<vector<int> > scc;
bool visited[MAX_V];
int V, E;
stack<int> st;
int sz;
void dfs(int here) {
	visited[here] = true;
	for (int there : vt[here]) {
		if (!visited[there]) {
			dfs(there);
		}
	}
	st.push(here);
}
void func(int here) {
	visited[here] = true;
	scc[sz - 1].push_back(here);
	for (int there : rvt[here]) {
		if (!visited[there]) {
			func(there);
		}
	}
}
bool cmp(vector<int> x, vector<int> y) {
	return x[0] < y[0];
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	vt.resize(V + 1);
	rvt.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		vt[t1].push_back(t2);
		rvt[t2].push_back(t1);
	}
	for (int i = 1; i <= V; i++) {
		if (!visited[i])
			dfs(i);
	}
	memset(visited, false, sizeof(visited));
	while (!st.empty()) {
		int tmp = st.top();
		st.pop();
		if (visited[tmp])
			continue;
		scc.resize(++sz);
		func(tmp);
	}
	for (int i = 0; i < scc.size(); i++) {
		sort(scc[i].begin(), scc[i].end());
	}
	sort(scc.begin(), scc.end(), cmp);
	cout << scc.size() << '\n';
	for (int i = 0; i < scc.size(); i++) {
		for (int idx = 0; idx < scc[i].size(); idx++) {
			cout << scc[i][idx] << ' ';
		}
		cout << "-1\n";
	}
}