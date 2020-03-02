//result:시간초과
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
int getSum[1001][101][101];
int src[101];
int maxNum;
int solve(int cnt, int num, int from) {
  //  cout << cnt << ' ' << num << ' ' << from << endl;
    if (cnt == s)
        return getSum[num][from][n];
    int& ret = cache[num][from];
    if (ret != -1) return ret;
    ret = getSum[num][from][n];
    for (int nextNum = num + 1; nextNum <= maxNum; nextNum++) {
        for (int nextFrom = from + 1; nextFrom <= n; nextFrom++) {
            ret = min(ret, getSum[num][from][nextFrom - 1] + solve(cnt + 1, nextNum, nextFrom));
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
        for (int i = 1; i <= n; i++)
            cin >> src[i];
        sort(src + 1, src + n + 1);
        src[0] = 0;
        maxNum = src[n];
        for (int num = 1; num <= 1000; num++) {
            for (int from = 1; from <= n; from++) {
                for (int to = from; to <= n; to++) {
                    getSum[num][from][to] = 0;
                    for (int i = from; i <= to; i++) {
                        getSum[num][from][to] += (src[i] - num) * (src[i] - num);
                    }
                }
            }
        }
        int ans = INF;
        for (int num = 1; num <= maxNum; num++) {
            ans = min(ans, solve(1, num, 1));
        }
        cout << ans << '\n';
    }
}