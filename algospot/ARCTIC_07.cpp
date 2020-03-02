//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int MAX_N = 100;
int n;
double position[MAX_N][2];//position[i][0] :x position[i][1] : y
double dist[MAX_N][MAX_N];
bool visited[MAX_N];
bool dfs(int here, int cnt,double dis) {
   // cout << here << ' '<<cnt<<' ' << dis << endl;
    /*if (cnt == n)
        return true;
        이것은 왜 안될까?
        visited[i]=false로 설정해둔 부분이 있을때에만 유효함
        visited[i]=false로 설정해둔 부분이 없으면 모든 visited가 true인지 확인하는 것으로 그래프가 완성되었는지 확인
        */
    visited[here] = true;
    bool isCan = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            isCan = false;
    }
    if (isCan)
        return true;
    for (int there = 0; there < n; there++) {
        if (!visited[there] && dist[here][there] <= dis) {
            visited[there] = true;
            if (dfs(there, cnt + 1, dis))
                return true;
        }
    }
    return false;
}
bool decision(double dis) {
    return dfs(0, 1, dis);
    for (int i = 0; i < n; i++)
        if (!visited[i])
            return false;
    return true;
}
double solve() {
    double lo = -1, hi = 1500;
    for (int i = 0; i < 100; i++) {
        memset(visited, 0, sizeof(visited));
        double mid = (lo + hi) / 2;
        //cout << "mid:" << mid << endl;
        if (decision(mid)) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return lo;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(2);
    int c;
  //  cout << getSize(1023);
    cin >> c;
    while (c--) {

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> position[i][0] >> position[i][1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = sqrt(pow(position[i][0] - position[j][0], 2) + pow(position[i][1] - position[j][1], 2));
            }
        }
        cout << solve() << '\n';
    }
}