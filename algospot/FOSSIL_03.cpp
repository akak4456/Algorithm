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
struct point {
    double y, x;
};
vector<point> hull1, hull2;
vector<pair<point, point> >upper, lower;
void decompose(const vector<point>& hull) {
    int n = hull.size();
    for (int i = 0; i < n; i++) {
        if (hull[i].x < hull[(i + 1) % n].x)
            lower.push_back(make_pair(hull[i], hull[(i + 1) % n]));
        else if (hull[i].x > hull[(i + 1) % n].x)
            upper.push_back(make_pair(hull[i], hull[(i + 1) % n]));
    }
}
bool between(const point& a, const point& b, double x) {
    return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}
double at(const point& a, const point& b, double x) {
    double dy = b.y - a.y, dx = b.x - a.x;
    return a.y + dy * (x - a.x) / dx;
}
double vertical(double x) {
    double minUp = 1e20, maxLow = -1e20;
    for (int i = 0; i < upper.size(); i++) {
        if (between(upper[i].first, upper[i].second, x))
            minUp = min(minUp, at(upper[i].first, upper[i].second, x));
    }
    for (int i = 0; i < lower.size(); i++) {
        if (between(lower[i].first, lower[i].second, x))
            maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));

    }
    return minUp - maxLow;
}
double minX(const vector<point>& hull) {
    double ret = 101;
    for (int i = 0; i < hull.size(); i++) {
        ret = min(ret, hull[i].x);
    }
    return ret;
}
double maxX(const vector<point>& hull) {
    double ret = -1;
    for (int i = 0; i < hull.size(); i++) {
        ret = max(ret, hull[i].x);
    }
    return ret;
}
double solve() {
    double lo = max(minX(hull1),minX(hull2));
    double hi = min(maxX(hull1),maxX(hull2));

    if (hi < lo) return 0;
    for (int iter = 0; iter < 100; iter++) {
        double aab = (lo * 2 + hi) / 3.0;
        double abb = (lo + hi * 2) / 3.0;
     //   cout <<aab<<' '<< vertical(aab) << ' '<<abb<<' ' << vertical(abb) << '\n';
        if (vertical(aab) < vertical(abb)) {
            lo = aab;
        }
        else {
            hi = abb;
        }
    }
    return max(0.0, vertical(hi));
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
        hull1.clear();
        hull2.clear();
        upper.clear();
        lower.clear();
        int n, m;
        cin >> n >> m;
        hull1.resize(n);
        hull2.resize(m);
        for (int i = 0; i < n; i++) {
            cin >> hull1[i].x >> hull1[i].y;
        }
        for (int i = 0; i < m; i++) {
            cin >> hull2[i].x >> hull2[i].y;
        }
        decompose(hull1);
        decompose(hull2);
        cout << solve() << '\n';
    }
}