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
using namespace std;
const int MOD = 10000000;
int cache[101][101];
int N;
int solve(int head, int remain) {
   // cout << head << ' ' << remain << endl;
    if (head > remain) return 0;
    if (remain == head) return 1;
    int& ret = cache[head][remain];
    if (ret != -1) return ret;
    ret = 0;
    for (int nextHead = 1; nextHead <= remain; nextHead++) {
        ret += (head + nextHead - 1) * solve(nextHead, remain - head);
        ret %= MOD;
    }
  //  cout << "ret:" << ret << endl;
    return ret%MOD;
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
        cin >> N;
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += solve(i, N);
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}