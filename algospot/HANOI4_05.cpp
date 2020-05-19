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
const int MAX_DISCS = 12;
int get(int state, int index) {
    return (state >> (index * 2)) & 3;
}
int setRod(int state, int index, int value) {
    return (state & ~(3 << index * 2)) | (value << (index * 2));
}
int c[1 << (MAX_DISCS * 2)];
int sgn(int x) {
    if (!x) return 0;
    return x > 0 ? 1 : -1;
}
int incr(int x) {
    if (x < 0)
        return x - 1;
    return x + 1;
}
int bidir(int discs, int begin, int end) {
    if (begin == end) return 0;
    queue<int> q;
    memset(c, 0, sizeof(c));
    q.push(begin); c[begin] = 1;
    q.push(end); c[end] = -1;
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        int top[4] = { -1,-1,-1,-1 };
        for (int i = discs - 1; i >= 0; i--)
            top[get(here, i)] = i;
        for(int i=0;i<4;i++)
            if(top[i] != -1)
                for(int j=0;j<4;j++)
                    if (i != j && (top[j] == -1 || top[j] > top[i])) {
                        int there = setRod(here,top[i], j);
                        if (c[there] == 0) {
                            c[there] = incr(c[here]);
                            q.push(there);
                        }
                        else if (sgn(c[there]) != sgn(c[here]))
                            return abs(c[there]) + abs(c[here]) - 1;
                    }
    }
    return -1;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n;
        cin >> n;
        int finish = 0;
        for (int i = 0; i < n; i++) {
            finish = setRod(finish, i, 3);
        }
        int start = 0;
        for (int i = 0; i < 4; i++) {
            int t;
            cin >> t;
            while (t--) {
                int k;
                cin >> k;
                start = setRod(start, k-1, i);
            }
        }
        cout << bidir(n,start, finish) << '\n';
    }
}