//정답
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
//bool dfs(int idx,int cnt,double dis) {
//   // cout << idx<<' '  << cnt << ' '<< dis << endl;
//    if (cnt == n)
//        return true;
//    visited[idx] = true;
//    for (int i = 0; i < n; i++) {
//        if (!visited[i]&&dist[i][idx] <= dis) {
//            if (dfs(i, cnt+1,dis)) {
//                return true;
//            }
//            //visited[i] = false;
//        }
//    }
//    visited[idx] = false;
//    return false;
//}
bool decision(double dis) {
    vector<bool> visited(n, false);
    visited[0] = true;
    stack<int> st;
    st.push(0);
    while (!st.empty()) {
      //  cout << st.size() << endl;
        int here = st.top();
        st.pop();
        visited[here] = true;
        bool isCan = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                isCan = false;
                break;
            }
        }
        if (isCan)
            return true;
        for (int there = 0; there < n; there++) {
            if (!visited[there] && dist[here][there] <= dis) {
                st.push(there);
            }
        }
        //seen--;
    }
    return false;
   // return dfs(0,1,dis);
}
double solve() {
    double lo = -1, hi = 1500;
    for (int i = 0; i < 100; i++) {
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