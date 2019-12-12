//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX_N = 100001;
const int MAX_I = (1 << 20);
int T;
int N;
vector<pair<int,int> > adj[MAX_N];
bool visited[MAX_N];
int d[MAX_N], par[MAX_N][21];
int M;
long long int Cost[MAX_N];
void dfs(int here, int depth) {
	visited[here] = true;
	d[here] = depth;
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i].first;
		if (!visited[there]) {
			par[there][0] = here;
			Cost[there] = Cost[here] + adj[here][i].second;
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
	if (d[x] > d[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i))
			y = par[y][i];
	}
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
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int t1, t2,t3;
		cin >> t1 >> t2 >> t3;
		adj[t1].push_back(make_pair(t2,t3));
		adj[t2].push_back(make_pair(t1, t3));
	}
	dfs(1, 0);
	f();
	cin >> M;
	while (M--) {
		int q;
		cin >> q;
		if (q == 1) {
			int q1, q2;
			cin >> q1 >> q2;
			int commonParent = lca(q1, q2);
			cout << (Cost[q1] + Cost[q2] - 2 * Cost[commonParent]) << '\n';
		}
		else if (q == 2) {
			int u, v, k;
			cin >> u >> v >> k;
			int commonParent = lca(u, v);
			int diff1 = d[u] - d[commonParent], diff2 = d[v] - d[commonParent];
			int remainK = k-1;
			if (diff1 >= remainK) {
				int ans = u;
				for (int i = 20; i >= 0; i--) {
					if (remainK >= (1 << i)) {
						remainK -= (1 << i);
						ans = par[ans][i];
					}
				}
				cout << ans << '\n';
			}
			else {
				remainK -= diff1;
				remainK = diff2 - remainK;
				int ans = v;
				for (int i = 20; i >= 0; i--) {
					if (remainK >= (1 << i)) {
						remainK -= (1 << i);
						ans = par[ans][i];
					}
				}
				cout << ans << '\n';
			}
		}
	}
}