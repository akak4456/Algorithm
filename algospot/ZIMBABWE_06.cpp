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
#include <cstdint> //or <stdint.h>
#include <limits>
#include <set>
using namespace std;
const int MOD = 1000000007;
int cache[10][1<<14][20][2];
//num len mod less
string e;
string originE;
int m;
int getLen(int used) {
    int ret = 0;
    for (int i = 0; i < e.size(); i++) {
        if ((used & (1 << i)) > 0) {
            ret++;
        }
    }
    return ret;
}
int toNumber(char ch) {
    return (int)(ch - '0');
}
int solve(int num, int used, int mod, int less) {
    //cout << "start:"<<num << ' ' << getLen(used) << ' ' << mod << ' ' << less << endl;
    if (getLen(used) == e.size()) {
        return (less == 1 && mod == 0);
    }
    int& ret = cache[num][used][mod][less];
    if (ret != -1) return ret;
    ret = 0;
   // cout << num<<" ABC\n";
    int lastUsed = -1;
    for (int i = 0; i < e.size(); i++) {
       // cout << getLen(used)<<" FOR\n";
        if ((used & (1 << i)) == 0) {
            //안 사용되었다면
            if (less == 0&&toNumber(e[i]) > toNumber(originE[getLen(used)]))
                continue;
            if (lastUsed == toNumber(e[i]))
                continue;
            lastUsed = toNumber(e[i]);
           // cout << e[i]<<' '<<num<<' '<< mod<<' '<<(mod * 10 + toNumber(e[i])) << endl;
            int newMod = (mod * 10 + toNumber(e[i]))%m;
            int newUsed = (used | (1 << i));
            int newLess = less;
            if (less == 0) {
                if (toNumber(e[i]) < toNumber(originE[getLen(used)])) {
                    newLess = 1;
                }
            }
            ret += solve(toNumber(e[i]), newUsed, newMod, newLess);
            ret %= MOD;
        }
    }
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        memset(cache, -1, sizeof(cache));
        cin >> e >> m;
        originE = e;
        sort(e.begin(), e.end());
        cout << solve(0, 0, 0, 0) << '\n';
    }
}