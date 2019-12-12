//result:정답
#include <iostream>
#include <vector>
using namespace std;
const int MAX_V = 1000;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
int V;
vector<int> adj[MAX_V];
vector<bool> visited;
int installed;

int dfs(int here) {
	visited[here] = true;
	int children[3] = { 0,0,0 };
	for (int i = 0; i < adj[here].size(); i++ ) {
		int there = adj[here][i];
		if (!visited[there])
			children[dfs(there)]++;
	}
	if (children[UNWATCHED]) {
		installed++;
		return INSTALLED;
	}
	if (children[INSTALLED]) {
		return WATCHED;
	}
	return UNWATCHED;
}
int installCamera() {
	installed = 0;
	visited = vector<bool>(V, false);
	for (int u = 0; u < V; u++) {
		if (!visited[u] && dfs(u) == UNWATCHED)
			installed++;
	}
	return installed;
}
int C;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		int H;
		cin >> V >> H;
		for (int i = 0; i < H; i++) {
			int from, to;
			cin >> from >> to;
			adj[from].push_back(to);
			adj[to].push_back(from);
		}
		installed = 0;
		cout << installCamera() << endl;
		for (int i = 0; i < V; i++)
			adj[i].clear();
	}
}