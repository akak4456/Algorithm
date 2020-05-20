//result:정답
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAX_V = 500;
const int INF = 987654321;
int V,E;
int delay[MAX_V];
int adj[MAX_V][MAX_V];
int W[500][500];
void solve() {
    vector<pair<int, int> > order;
    for (int i = 0; i < V; i++)
        order.push_back(make_pair(delay[i], i));
    sort(order.begin(), order.end());
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (i == j)
                W[i][j] = 0;
            else
                W[i][j] = adj[i][j];
    int ret = INF;
    for (int k = 0; k < V; k++) {
        int w = order[k].second;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
                W[i][j] = min(adj[i][w] + delay[w] + adj[w][j], W[i][j]);
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i < V; i++)
        cin >> delay[i];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = INF;
    for (int i = 0; i < E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--;
        B--;
        adj[A][B] = C;
        adj[B][A] = C;
    }
    solve();
    int T;
    cin >> T;
    while (T--) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        cout << W[s][t] << '\n';
    }
}