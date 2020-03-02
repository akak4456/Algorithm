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
int cache[1001][101][101];
int src[101];
int maxNum;
int getSum(int num, int from, int to) {
    int ret = 0;
    for (int i = from; i <= to; i++)
        ret += (src[i] - num) * (src[i] - num);
    return ret;
}
int solve(int cnt, int num, int from, int to) {
   // cout << cnt << ' ' << num << ' ' << from << ' ' << to << endl;
    if (cnt == s)
        return getSum(num,from,n);
    if (to == n)
        return getSum(num, from, to);
    int& ret = cache[num][from][to];
    if (ret != -1) return ret;
    ret = INF;
    int sum = getSum(num, from, to);
    for (int nextNum = num + 1; nextNum <= maxNum; nextNum++) {
        int nextFrom = to + 1;
        for (int nextTo = nextFrom; nextTo < n; nextTo++)
            ret = min(ret, sum+solve(cnt+1,nextNum, nextFrom, nextTo));
    }
 //   cout << ret << endl;
    return ret;
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
        memset(cache, -1, sizeof(cache));
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
            cin >> src[i];
        sort(src+1, src + n+1);
        maxNum = src[n];
        src[0] = 0;
        cout << solve(0, 0, 0, 0) << '\n';
    }
}