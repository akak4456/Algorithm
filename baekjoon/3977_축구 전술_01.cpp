//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> g[101010];
vector<int> rev[101010];
int chk[101010];
vector<int> dfn;
int scc[101010];
vector< vector<int> > comp;
int n, m;

void dfs(int v) {
	chk[v] = 1;
	for (auto i : g[v]) {
		if (chk[i]) continue;
		dfs(i);
	}
	dfn.push_back(v);
}

void dfs_rev(int v, int color) {
	scc[v] = color;
	comp.back().push_back(v);
	for (auto i : rev[v]) {
		if (scc[i]) continue;
		dfs_rev(i, color);
	}
}

void getSCC() {
	memset(chk, 0, sizeof chk);
	dfn.clear();
	memset(scc, 0, sizeof scc);
	comp.clear();

	for (int i = 1; i <= n; i++) {
		if (!chk[i]) dfs(i);
	}
	reverse(dfn.begin(), dfn.end());
	int pv = 0;
	for (auto i : dfn) {
		if (scc[i]) continue;
		comp.push_back(vector<int>());
		dfs_rev(i, ++pv);
	}
}

void init() {
	for (int i = 0; i < 101010; i++) g[i].clear(), rev[i].clear();
}

void solve() {
	init();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		g[a+1].push_back(b+1);
		rev[b+1].push_back(a+1);
	}
	getSCC();
	int ans = 0;
	vector<int> result;
	for (auto& i : comp) {
		bool flag = 0;
		for (auto& j : i) {
			for (auto& k : rev[j]) {
				if (scc[j] == scc[k]) continue;
				flag = 1;
			}
		}
		ans += !flag;
		if (flag == 0) {
			for (int tmp : i) {
				result.push_back(tmp);
			}
		}
	}
	if (ans == 0 || ans >= 2) {
		cout << "Confused\n";
	}
	else {
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) {
			cout << (result[i]-1) << '\n';
		}
	}
	cout <<  "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
}