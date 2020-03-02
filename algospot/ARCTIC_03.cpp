//result:시간초과
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX_N = 100;
int n;
double position[MAX_N][2];//position[i][0] :x position[i][1] : y
bool visited[MAX_N];
bool dfs(int idx,int cnt,double dis) {
   // cout << idx<<' '  << cnt << ' '<< dis << endl;
    if (cnt == n)
        return true;
    visited[idx] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]&&sqrt(pow(position[i][0]-position[idx][0],2)+ pow(position[i][1] - position[idx][1], 2)) <= dis) {
            visited[i] = true;
            if (dfs(i, cnt+1,dis)) {
                return true;
            }
          visited[i] = false;
        }
    }
    visited[idx] = false;
    return false;
}
bool decision(double dis) {
    return dfs(0,1,dis);
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
        cout << solve() << '\n';
    }
}