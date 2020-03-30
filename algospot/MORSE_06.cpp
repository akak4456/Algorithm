//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <map>
using namespace std;
int cache[101][101];
int n, m, k;
const int MOD = 1000000000;
int solve(int remain1, int remain2) {
    int& ret = cache[remain1][remain2];
    if (ret != -1) return ret;
    if (remain1 == 0)
        return ret = 1;
    if (remain2 == 0)
        return ret = 1;
    ret = solve(remain1 - 1, remain2);
    if (ret > MOD) {
        ret = MOD;
        return ret;
    }
    ret += solve(remain1, remain2 - 1);
    if (ret > MOD) {
        ret = MOD;
        return ret;
    }
    return ret;
}
vector<char> result;
void print(int n,int m,int k) {
    //cout << n << ' ' << m << ' ' << k << endl;
    if (n == 0) {
        for (int i = 0; i < m; i++)
            result.push_back('o');
        return;
    }
    if (m == 0) {
        for (int i = 0; i < n; i++)
            result.push_back('-');
        return;
    }
   // cout << cache[n - 1][m] << endl;
    if (k <= cache[n - 1][m]) {
        result.push_back('-');
        print(n - 1, m, k);
        return;
    }
    k -= cache[n - 1][m];
    result.push_back('o');
    print(n, m - 1, k);
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        result.clear();
        memset(cache, -1, sizeof(cache));
        cin >> n >> m >> k;
        solve(n, m);
        print(n, m, k);
        for (char c : result) {
            cout << c;
        }
        cout << '\n';
    }
}