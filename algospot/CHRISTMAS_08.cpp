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
const int MOD = 20091101;
const int MAX_N = 100000;
const int MAX_K = 100000;
int N, K;
int D[MAX_N + 1];
int psum[MAX_N + 1];
int solve1() {
    int ret = 0;
    vector<long long int> count(K, 0);
    for (int i = 0; i <= N; i++)
        count[psum[i]]++;

    for (int i = 0; i < K; i++) {
        ret += count[i] * (count[i] - 1) / 2;
        ret %= MOD;
    }
    return ret;
}
int solve2() {
    vector<int> ret(N+1, 0);
    vector<int> prev(K, - 1);
    for (int i = 0; i <= N; i++) {
        if (i > 0)
            ret[i] = ret[i - 1];
        int loc = prev[psum[i]];
        if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
        prev[psum[i]] = i;
    }
    return ret.back();
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        memset(psum, 0, sizeof(psum));
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
        }
        for (int i = 1; i <= N; i++) {
            psum[i] = psum[i - 1];
            psum[i] += D[i];
            psum[i] %= K;
          //  cout << psum[i] << endl;
        }
        cout << solve1() << ' ' <<solve2() << '\n';
    }
}