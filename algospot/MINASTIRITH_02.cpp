//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const double pi = 2.0 * acos(0);
int n;
double y[100], x[100], r[100];
pair<double, double> ranges[100];
void convertToRange() {
    for (int i = 0;i < n;i++) {
        double loc = fmod(2 * pi + atan2(y[i], x[i]), 2 * pi);
        double range = 2.0 * asin(r[i] / 16.0);
        ranges[i] = make_pair(loc - range, loc + range);
    }
    sort(ranges, ranges + n);
}
const int INF = 987654321;
int solveLinear(double begin, double end) {
    int used = 0, idx = 0;
    while (begin < end) {
        double maxCover = -1;
        while (idx < n && ranges[idx].first <= begin) {
            maxCover = max(maxCover, ranges[idx].second);
            idx++;
        }
        if (maxCover <= begin) return INF;
        begin = maxCover;
        ++used;
    }
    return used;
}
int solveCircular() {
    int ret = INF;
    sort(ranges, ranges + n);
    for (int i = 0;i < n;i++) {
        if (ranges[i].first <= 0 || ranges[i].second >= 2 * pi) {
            double begin = fmod(ranges[i].second, 2 * pi);
            double end = fmod(ranges[i].first + 2 * pi, 2 * pi);

            ret = min(ret, 1 + solveLinear(begin, end));
        }
    }
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
        cin >> n;
        for (int i = 0;i < n;i++)
            cin >> y[i] >> x[i] >> r[i];
        convertToRange();
        int ans = solveCircular();
        if (ans == INF) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            cout << ans << '\n';
        }
      //  cout << solveCircular();
    }
}