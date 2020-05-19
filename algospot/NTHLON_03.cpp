//result:정답
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 402;
const int START = 401;
const int INF = 987654321;
int V;
vector<pair<int, int> >adj[MAX_V];
vector<int> dijkstra(int src) {
    vector<int> dist(V+1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int> >pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost)  continue;
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}
int vertex(int delta) {
    return delta + 200;
}
int solve(const vector<int>& a, const vector<int>& b) {
    V = 402;
    for (int i = 0; i < V; i++) adj[i].clear();
    for (int i = 0; i < a.size(); i++) {
        int delta = a[i] - b[i];
        adj[START].push_back(make_pair(vertex(delta), a[i]));
    }
    for (int delta = -200; delta <= 200; delta++) {
        for (int i = 0; i < a.size(); i++) {
            int next = delta + a[i] - b[i];
            if (abs(next) > 200) continue;
            adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
        }
    }
    vector<int> shortest = dijkstra(START);
    int ret = shortest[vertex(0)];
    if (ret == INF) return -1;
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n;
        cin >> n;
        vector<int>a, b;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        int ans = solve(a, b);
        if (ans == -1) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << ans << '\n';
        }
    }
}