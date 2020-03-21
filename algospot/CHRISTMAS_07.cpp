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
const int MOD = 20091101;
const int MAX_N = 100000;
const int MAX_K = 100000;
int N, K;
int D[MAX_N + 1];
int psum[MAX_N + 1];
int ret[MAX_N + 1];
int solve1() {
    int newPSUM[MAX_N + 1];
    for (int i = 0; i <= N; i++)
        newPSUM[i] = psum[i];
    sort(newPSUM + 1, newPSUM + N + 1);
    int ret = 0;
    int prevIdx = 0;
    int prevNum = 0;
    for (int i = 1; i <= N; i++) {
        //   cout << psum[i] << endl;
        if (newPSUM[i] != prevNum) {
            int gap = i - prevIdx;
            //cout << i<<' '<< gap << endl;
            ret += gap * (gap - 1) / 2;
            ret %= MOD;
            prevNum = newPSUM[i];
            prevIdx = i;
        }
        else if (i == N) {
            int gap = i - prevIdx + 1;
            //cout << i<<' '<< gap << endl;
            ret += gap * (gap - 1) / 2;
            ret %= MOD;
        }
    }
    return ret;
}
int solve2() {
    for (int i = 1; i <= N; i++) {
        ret[i] = ret[i - 1];
        for (int j = i - 1; j >= 0; j--) {
            if (psum[i] == psum[j]) {
                ret[i] = max(ret[i], ret[j] + 1);
                break;
            }
        }
    }
    return ret[N];
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
        memset(ret, 0, sizeof(ret));
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