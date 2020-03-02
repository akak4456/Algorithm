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
int src[101], pSum[101], pSqSum[101];
void precalc() {
    sort(src, src + n);
    pSum[0] = src[0];
    pSqSum[0] = src[0] * src[0];
    for (int i = 1; i < n; i++) {
        pSum[i] = pSum[i - 1] + src[i];
        pSqSum[i] = pSqSum[i - 1] + src[i] * src[i];
    }
}
int minError(int m,int from, int to) {
    int sum = pSum[to] - (from == 0 ? 0 : pSum[from - 1]);
    int sqSum = pSqSum[to] - (from == 0 ? 0 : pSqSum[from - 1]);
    int ret = sqSum - 2 * m * sum + m * m * (to - from + 1);
    return ret;
}
int maxNum;
int solve(int cnt, int num, int from) {
    
    if (cnt == s)
        return minError(num,from,n-1);
    
    int& ret = cache[num][from];
    if (ret != -1) return ret;
    ret = minError(num, from, n - 1);
    //cout << cnt << ' ' << num << ' ' << from << endl;
    for (int nextNum = num + 1; nextNum <= 1000; nextNum++) {
        for (int nextFrom = from + 1; nextFrom <= n; nextFrom++) {
          //  cout << minError(num, from, nextFrom - 1) << endl;
            ret = min(ret, minError(num, from, nextFrom - 1) + solve(cnt + 1, nextNum, nextFrom));
        }
    }
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
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> src[i];
        precalc();
        int ans = INF;
        for (int num = 1; num <= 1000; num++) {
            ans = min(ans, solve(1, num, 0));
        }
        cout << ans << '\n';
    }
}