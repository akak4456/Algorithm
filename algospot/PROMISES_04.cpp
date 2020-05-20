//result:오답
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAX_V = 200;
const int INF = 987654321;
int V;
int M, N;
int adj[MAX_V][MAX_V];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        cin >> V >> M >> N;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = INF;
            }
        }
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] = c;
            adj[b][a] = c;
        }
        for (int i = 0; i < V; i++) adj[i][i] = 0;
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        int ans = 0;
        for (int step = 0; step < N; step++) {
            int a, b, c;
            cin >> a >> b >> c;
            int oldAdj = adj[a][b];
            if (adj[a][b] != INF && adj[a][b] <= c) {
                //이미 도로가 있었다.
                ans++;
                continue;
            }
            //일단 한번 도로를 지어봐
            adj[a][b] = c;
            adj[b][a] = c;
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    adj[i][j] = min(adj[i][j], adj[i][a] + adj[a][j]);
                    adj[i][j] = min(adj[i][j], adj[i][b] + adj[b][j]);
                }
            }
            if (adj[a][b] == oldAdj) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}