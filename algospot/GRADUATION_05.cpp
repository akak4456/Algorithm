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
const int MAX_N = 12;
const int MAX_M = 10;
int cache[1 << MAX_N][MAX_M];
int prereq[MAX_N];
int sem[MAX_M];
int N, K, M, L;
bool isAvailable(int taking,int pre) {
    for (int i = 0; i < N; i++) {
        if (taking & (1 << i)) {
            if ((pre & prereq[i]) != prereq[i]) {
                return false;
            }
        }
    }
    return true;
}
int getCnt(int taken) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        if (taken & (1 << i))
            ret++;
    }
    return ret;
}
int solve(int taken, int semester) {
   cout << "parameter " <<taken << ' ' << semester << ' ' <<getCnt(taken)<< endl;
    if (getCnt(taken) >= K)
        return 0;
    if (semester >= M)
        return -2;
    int& ret = cache[taken][semester];
    if (ret != -1) return ret;
    ret = -2;
    int fullSet = (sem[semester] & ~taken);
    for (int subset = fullSet; subset; subset = ((subset - 1) & fullSet)) {
        if (getCnt(subset) > L)
            continue;
        if (isAvailable(subset,taken)) {
            int ans = solve(taken | subset, semester + 1);
         //   cout << "parameter " << taken << ' ' << semester<< " ans:" << ans << endl;
            if (ans != -2) {
                if (ret == -2)
                    ret = ans + 1;
                else
                    ret = min(ret, ans + 1);
            }
        }
    }
  // cout << "parameter " << taken << ' ' << semester<< " ret:" << ret << endl;
    int ans = solve(taken, semester + 1);
    if (ans != -2) {
        if (ret == -2)
            ret = ans;
        else
            ret = min(ret, ans);
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
        memset(prereq, 0, sizeof(prereq));
        memset(sem, 0, sizeof(sem));
        cin >> N >> K >> M >> L;
        for (int i = 0; i < N; i++) {
            int t;
            cin >> t;
            while (t--) {
                int t2;
                cin >> t2;
                prereq[i] |= (1 << t2);
            }
        }
        for (int i = 0; i < M; i++) {
            int t;
            cin >> t;
            while (t--) {
                int t2;
                cin >> t2;
                sem[i] |= (1 << t2);
            }
        }
      //  cout <<"available:"<< isAvailable(4) << endl;
        int ans = solve(0, 0);
        if (ans == -2)
            cout << "IMPOSSIBLE\n";
        else
            cout << ans -1<< '\n';
      //  cout << solve(0, 0) << '\n';
    }
}