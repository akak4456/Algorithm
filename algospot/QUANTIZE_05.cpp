//result:시간초과
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int INF = 987654321;
int n, s;
int cache[1001][101];
int cache2[1001][101][101];
int src[101];
int maxNum;
int getSum(int num, int from, int to) {
    int& ret = cache2[num][from][to];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = from; i <= to; i++)
        ret += (src[i] - num) * (src[i] - num);
    return ret;
}
int solve(int cnt, int num, int from) {
    // cout << cnt << ' ' << num << ' ' << from << ' ' << to << endl;
    if (cnt == s)
        return getSum(num, from, n);
    int& ret = cache[num][from];
    if (ret != -1) return ret;
    ret = INF;
    for (int nextNum = num + 1; nextNum <= maxNum; nextNum++) {
        for (int nextFrom = from + 1; nextFrom < n; nextFrom++)
            ret = min(ret, getSum(num, from, nextFrom - 1) + solve(cnt + 1, nextNum, nextFrom));
    }
    //   cout << ret << endl;
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        memset(cache, -1, sizeof(cache));
        memset(cache2, -1, sizeof(cache2));
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
            cin >> src[i];
        sort(src + 1, src + n + 1);
        maxNum = src[n];
        src[0] = 0;
        cout << solve(0, 0, 0) << '\n';
    }
}