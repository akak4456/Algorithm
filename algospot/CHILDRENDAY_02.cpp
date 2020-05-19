//result:런타임 오류
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
string D;
int N, M;
string solve() {
    set<long long int> discovered;
    queue < pair<int, long long int > >q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        pair<int, long long int >tp = q.front();
        long long int oldTp = tp.second;
        q.pop();
        for (int i = 0; i < D.size(); i++) {
            int nxt = (tp.first * 10 + (D[i]-'0'))%N;
            int newTp = tp.second * 10 + (D[i] - '0');
            if (discovered.find(newTp) == discovered.end()) {
                discovered.insert(newTp);
                tp.second = newTp;
                q.push(make_pair(nxt, tp.second));
                if (nxt == M && tp.second >= N)
                    return to_string(tp.second);
                tp.second = oldTp;;
            }
        }
    }
    return "IMPOSSIBLE";
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        cin >>D>> N >> M;
        cout << solve() << '\n';
    }
}