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
int n;
int board[50];
int cache[50][50];
int play(int left, int right) {
    if (left > right)
        return 0;
    if (left == right)
        return board[left];
    int& ret = cache[left][right];
    if (ret != -1)return ret;
    ret = -987654321;
    ret = max(ret, -play(left + 1, right) + board[left]);
    ret = max(ret, -play(left, right - 1) + board[right]);
    if (right - left >= 1) {
        ret = max(ret, -play(left + 2, right));
        ret = max(ret, -play(left, right - 2));
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
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> board[i];
        cout << play(0, n - 1) << '\n';
    }
}