//result:정답
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
            //입력받는 부분에서 틀렸음
            adj[a][b] = min(adj[a][b],c);
            adj[b][a] = min(adj[b][a],c);
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
            if (adj[a][b] <= c) {
                ans++;
                continue;
            }
            for (int x = 0; x < V; x++) {
                for (int y = 0; y < V; y++) {
                    adj[x][y] = min(adj[x][y], adj[x][a] + adj[b][y] + c);
                    adj[x][y] = min(adj[x][y], adj[x][b] + adj[a][y] + c);
                }
            }
        }
        cout << ans << '\n';
    }
}