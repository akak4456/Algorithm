//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include <cstdint> //or <stdint.h>
#include <limits>
#include <set>
using namespace std;
const int MAX_V = 1000;
int V,H;
vector<int> adj[MAX_V];
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
int installed;
int dfs(int here) {
    visited[here] = true;
    int children[3] = { 0,0,0 };
    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if (!visited[there]) {
            children[dfs(there)]++;
        }
    }
    if (children[UNWATCHED]) {
        installed++;
        return INSTALLED;
    }
    if (children[INSTALLED])
        return WATCHED;
    return UNWATCHED;
}
int installCamera() {
    installed = 0;
    visited = vector<bool>(V, false);
    for (int u = 0; u < V; u++)
        if (!visited[u] && dfs(u) == UNWATCHED)
            installed++;
    return installed;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        for (int i = 0; i < MAX_V; i++)
            adj[i].clear();
        cin >> V >> H;
        for (int i = 0; i < H; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            adj[t1].push_back(t2);
            adj[t2].push_back(t1);
        }
        cout << installCamera() << '\n';
    }
}