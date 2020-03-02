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
int n, k;
vector<pair<int, int> > input1;
vector<pair<int, int> > input2;
bool decision(double x) {
    double sumR = 0,sumC = 0;
    for (int i = 0; i < input1.size(); i++) {
        sumR += input1[i].first;
        sumC += input1[i].second;
        if (i >= k - 1) {
            if (sumR <= x * sumC)
                return true;
        }
    }
    sumR = sumC = 0;
    for (int i = 0; i < input2.size(); i++) {
        sumR += input2[i].second;
        sumC += input2[i].first;
        if (i >= k - 1) {
            if (sumR <= x * sumC)
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
    int c;
  //  cout << getSize(1023);
    cin >> c;
    while (c--) {
        input1.clear();
        input2.clear();
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            input1.push_back(make_pair(t1, t2));
            input2.push_back(make_pair(t2, t1));
        }
        cout << solution() << '\n';
    }
}