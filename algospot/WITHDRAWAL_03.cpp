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
int n, k;
int r[1000], c[1000];
bool decision(double x) {
    vector<double> v;
    for (int i = 0; i < n; i++) {
        v.push_back(-(x * c[i] - r[i]));
    }
    sort(v.begin(), v.end());
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += -v[i];
        if (i >= k - 1) {
            if (sum >= 0)
                return true;
        }
    }
    return false;
}
double solution() {
    double lo = 0, hi = 1;
    for (int i = 0; i < 50; i++) {
        double mid = (lo + hi) / 2;
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
    cout.precision(10);
    int test_case;
  //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> r[i] >> c[i];
        }
        cout << solution() << '\n';
    }
}