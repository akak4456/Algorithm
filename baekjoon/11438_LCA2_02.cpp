//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N = 100001;
int T;
int N;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int d[MAX_N],par[MAX_N][21];
void dfs(int here, int depth) {
	visited[here] = true;
	d[here] = depth;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there]) {
			par[there][0] = here;
			dfs(there, depth + 1);
		}
	}
}
void f() {
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= N; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}
int lca(int x, int y) {
	
	while (d[x] != d[y]) {
		int ni = 20;
		while ((1<<ni) > abs(d[x] - d[y])) {
			ni--;
		}
		if (d[x] > d[y]) {
			x = par[x][ni];
		}
		else if (d[x] < d[y]) {
			y = par[y][ni];
		}
	}
	/*
	if (d[x] > d[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i))
			y = par[y][i];
	}
	*/
	if (x == y)
		return x;
	for (int j = 20; j >= 0; j--) {
		if (par[x][j] != par[y][j]) {
			x = par[x][j];
			y = par[y][j];
		}
	}
	return par[x][0];
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//cin >> T;
	//while (T--) {
		for (int i = 0; i < MAX_N; i++) {
			adj[i].clear();
			visited[i] = false;
			d[i] = 0;
			for (int j = 0; j < 21; j++) {
				par[i][j] = 0;
			}
		}
		cin >> N;
		for (int i = 0; i < N - 1; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			adj[t1].push_back(t2);
			adj[t2].push_back(t1);
		}
		dfs(1, 0);
		//cout << d[2] << endl;
		f();
		int m;
		cin >> m;
		while (m--) {
			int q1, q2;
			cin >> q1 >> q2;
			//cout << par[q1][0] << ' ' << par[q2][0] << endl;
			cout << lca(q1, q2) << '\n';
		}
	//}
}