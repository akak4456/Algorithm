//result:오답
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 100;
const int M = 10000;
const int INF = 987654321;
int V;
vector<pair<int, int> >adj[MAX_V];
vector<int> bellmanFord(int src) {
    vector<int> upper(V, INF);
    upper[src] = 0;
    bool updated;

    for (int iter = 0; iter < V; iter++) {
        updated = false;
        for (int here = 0; here < V; here++) {
            for (int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                if (upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }
    if (updated) upper.clear();
    return upper;
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
        int W;
        cin >> V >> W;
        for (int i = 0; i < W; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back(make_pair(b, d));
        }
        vector<int> ans = bellmanFord(0);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                adj[i][j].second *= -1;
            }
        }
        vector<int> ans2 = bellmanFord(0);
        if ((!ans.empty()&&ans[1] > INF - M) || (!ans2.empty()&&ans2[1] < -(INF-M))) {
            cout << "UNREACHABLE\n";
        }
        else {
            if (!ans.empty()) {
                cout << ans[1] << ' ';
            }
            else {
                cout << "INFINITY\n";
            }
            if (!ans2.empty()) {
                cout << -ans2[1] << '\n';
            }
            else {
                cout << "INFINITY\n";
            }
        }
    }
}