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
int n;
vector<double> term;
vector<double> ans;
double getX(double x) {
    double newX = 1;
    double ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += term[n - i] * newX;
        newX *= x;
    }
    return ret;
}
double solve(double lo, double hi) {
  //  cout << lo << ' ' << hi << endl;
    for (int i = 0; i < 100; i++) {
      //  cout << lo << ' ' << hi << ' ';
        double mid = (lo + hi) / 2;
      //  cout <<getX(lo)<<' '<<getX(mid) << ' ' <<getX(hi) << endl;
        if (getX(mid) == 0)
            return mid;
        else if (getX(mid) > 0) {
            if (getX(lo) > 0) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
        else if (getX(mid) < 0) {
            if (getX(lo) < 0) {
                lo = mid;
            }
            else {
                hi = mid;
            }
        }
    }
    return (lo + hi) / 2;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(12);
    int test_case;
  //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        term.clear();
        ans.clear();
        cin >> n;
        term.resize(n + 1);
        for (int i = 0; i <= n; i++)
            cin >> term[i];
        double hi = 10.0;
        int hiSign = -1;
        for (double i = 10.0; i >= -10.0; i-=0.01) {
            if (hiSign == -1) {
                if (getX(i) > 0) {
                    hiSign = 0;
                }
                else if (getX(i) == 0) {
                    ans.push_back(i);
                    hi = i;
                }
                else {
                    hiSign = 1;
                }
            }
            else if (hiSign == 0) {
                //f_hi가 양수 일때
                if (getX(i) < 0) {
                    ans.push_back(solve(i,hi));
                    hi = i;
                    hiSign = -1;
                }
            }
            else {
                //f_hi가 음수 일때
                if (getX(i) >= 0) {
                    ans.push_back(solve(i, hi));
                    hi = i;
                    hiSign = -1;
                }
            }
        }
        sort(ans.begin(), ans.end());
        for (double a : ans) {
            cout << a << ' ';
        }
        cout << '\n';
    }
}