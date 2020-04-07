//result:오답
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
using namespace std;
const int MAX = 1000000000 + 1;
int cache[51];
int n, p, l;
char solve(string seed,int idx, int depth) {
   // cout << seed << ' ' << idx << ' ' << depth << endl;
    if (idx <= seed.size()) {
        return seed[idx-1];
    }
    for (int i = 0; i < seed.size(); i++) {
        if (seed[i] == 'X') {
            if (idx <= cache[n - depth]) {
                return solve("X+YF", idx, depth + 1);
            }
            else {
                idx -= cache[n - depth];
            }
        }else if (seed[i] == 'Y') {
            if (idx <= cache[n - depth]) {
                return solve("FX-Y", idx, depth + 1);
            }
            else {
                idx -= cache[n - depth] ;
            }
        }
        else {

            idx--;
            if (idx == 0)
                return seed[i];
        }
        //cout << seed[i]<<' '<<idx << endl;
        //cout << idx << endl;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cache[0] = 1;
    for (int i = 1; i <= 50; i++) {
        cache[i] = cache[i-1] * 2 + 2;
        if (cache[i] >= MAX)
            cache[i] = MAX;
       //cout << cache[i] << endl;
    }
    //cout << cache[50] << endl;
    int test_case;
    cin >> test_case;
    while (test_case--) {
        cin >> n >> p >> l;
        string ans = "";
        for (int idx = p; idx < p + l; idx++) {
            ans += solve("FX", idx, 0);
        }
        cout << ans << '\n';
    }
}