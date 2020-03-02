//result:오답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
int n, m;
int calc(long x) {
    return( (m + x) * 1.0 / (n + x) )*100;
}
const int INF = 987654321;
int solve() {
    int lo = -1, hi = INF;
    for (int iter = 0; iter < 100; iter++) {
        int mid = (lo + hi) / 2;
     // cout << mid << " " << calc(mid) << endl;
        if (calc(mid) >= (int)((m*1.0/n)*100+1)) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return hi;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(10);
    int test_case;
  //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        cin >> n >> m;
        int ans = solve();
        if (ans == INF) {
            cout << "-1\n";
        }
        else {
            cout << ans << "\n";
        }
    }
}