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
long long int n, m;
long long int calc(long long int x) {
    return (m + x) * 100 / (n + x);
}
const int INF = 2000010000;
long long int solve() {
    long long int lo = -1, hi = INF;
    for (int iter = 0; iter < 100; iter++) {
        long long int mid = (lo + hi) / 2;
     // cout << mid << " " << calc(mid) << endl;
        if (calc(mid) >= m*100/n+1) {
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