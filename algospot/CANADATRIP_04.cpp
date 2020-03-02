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
vector<pair<int,pair<int,int> > > cities;
bool decision(int x) {
    int cnt = 0;
    for (int i = 0; i < cities.size(); i++) {
        int l = cities[i].first;
        int m = cities[i].second.first;
        int g = cities[i].second.second;
        if (x < l) {
            if (x > l - m) {
                cnt += (x-l+m)/g+1;
            }
        }
        else {
            cnt += m / g + 1;
        }
    }
  //  cout <<x << ' '<<cnt << endl;
    return cnt >= k;
}
int solve() {
    int lo = -1, hi = 8030001;
    for (int i = 0; i < 50; i++) {
        int mid = (lo + hi) / 2;
        if (decision(mid)) {
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
    int c;
  //  cout << getSize(1023);
    cin >> c;
    while (c--) {
        cities.clear();
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int l, m, g;
            cin >> l >> m >> g;
            cities.push_back(make_pair(l, make_pair(m, g)));
        }
        sort(cities.begin(), cities.end());
        cout << solve() << '\n';
    }
}