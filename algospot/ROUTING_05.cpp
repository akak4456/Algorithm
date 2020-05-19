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
#include <cstdint>
#include <limits>
#include <set>
using namespace std;
typedef double DIS;
const int MAX_V = 10000;
const double INF = 10e300;
int V;
vector<pair<int, DIS> > adj[MAX_V];
vector<DIS> dijkstra(int src) {
   // cout << "src:" << src << endl;
    vector<DIS> dist(V, INF);
    dist[src] = 1;
    priority_queue<pair<DIS, int> >pq;
    pq.push(make_pair(-1, src));
    while (!pq.empty()) {
        DIS cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if (dist[here] < cost) continue;
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            DIS nextDist = cost * adj[here][i].second;
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
    cout<<fixed;
    cout.precision(10);
    while (test_case--) {
        for (int i = 0; i < MAX_V; i++)
            adj[i].clear();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            DIS d;
            cin >> a >> b >> d;
            adj[a].push_back(make_pair(b, d));
            adj[b].push_back(make_pair(a, d));
        }
        V = n;
        vector<DIS> ans = dijkstra(0);
        cout << ans[n-1] << '\n';
    }
}