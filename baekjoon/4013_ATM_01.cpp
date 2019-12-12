//result:틀렸습니다
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX_V = 500000 + 1;
vector<vector<int> > vt;
vector<vector<int> > rvt;
vector<vector<int> > scc;
int cash[MAX_V];
bool isRestaurant[MAX_V];
int sccId[MAX_V];
bool visited[MAX_V];
int V, E;
stack<int> st;
vector<pair<int, bool> > sccComponent;
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
vector<int> topological;
void func(int here) {
	visited[here] = true;
	scc[sz - 1].push_back(here);
	sccId[here] = sz - 1;
	bool isEdit = false;
	for (int there : rvt[here]) {
		if (!visited[there]) {
			isEdit = true;
			func(there);
		}
	}
	if (!isEdit) {
		topological.push_back(here);
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
	for (int i = 1; i <= V; i++) {
		cin >> cash[i];
	}
	int S, P;
	cin >> S >> P;
	for (int i = 0; i < P; i++) {
		int t;
		cin >> t;
		isRestaurant[t] = true;
	}
	sccComponent.resize(scc.size());
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			int here = scc[i][j];
			sccComponent[i].first += cash[here];
			if (isRestaurant[here]) {
				sccComponent[i].second = true;
			}
		}
	}
	int maxCash = -1;
	for (int i = 0; i < topological.size(); i++) {
		int here = topological[i];
		if (sccId[S] == sccId[here]) {
			for (int j = i; j < topological.size(); j++) {
				int there = topological[j];

			}
			break;
		}
	}
	cout << maxCash << '\n';
}