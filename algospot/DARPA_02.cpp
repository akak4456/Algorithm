//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 200;
int n, m;
double location[MAX_M];
bool decision(int idx, int remainCamera, double x) {
    if (remainCamera == 0)
        return true;
    for (int i = idx + 1; i < m; i++) {
        double diff = location[i] - location[idx];
        if (diff >= x) {
            if (decision(i, remainCamera - 1, x)) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}
double solve() {
    double lo = -1, hi = 241;
    for(int i=0;i<20;i++){
        //cout << lo << ' ' << hi << endl;
        double mid = (lo + hi) / 2;
        if (decision(0, n - 1, mid)) {
            lo = mid;
        }
        else {
            hi = mid;
        }
    }
    return hi;
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
        cin >> n >> m;
        for (int i = 0; i < m; i++)
            cin >> location[i];
        cout << solve() << '\n';
    }
}