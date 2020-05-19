//result:정답
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V = 1001;
const int INF = 987654321;
int V,E,n,m;
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
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        cin >> V >> E >> n >> m;
        for (int i = 0; i < MAX_V; i++)
            adj[i].clear();
        for (int i = 0; i < E; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back(make_pair(b, d));
            adj[b].push_back(make_pair(a, d));
        }
        vector<int> firePoint;
        firePoint.resize(n);
        for (int i = 0; i < n; i++)
            cin >> firePoint[i];
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            adj[0].push_back(make_pair(a, 0));
            adj[a].push_back(make_pair(0, a));
        }
        vector<int> ans = dijkstra(0);
        int sum = 0;
        for (int i = 0; i < firePoint.size(); i++) {
            sum += ans[firePoint[i]];
        }
        cout << sum << '\n';
    }
}