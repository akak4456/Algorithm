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
#include <set>
using namespace std;
class State {
public:
    long long int rod[4];
    vector<State> getAdjacent() const {
        vector<State> ret;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j)
                    continue;
                //i에서 j로 옮기기 가능?
                if ((rod[i] & 15) < (rod[j] & 15)) {
                    State newState;
                    for (int t = 0; t < 4; t++) {
                        newState.rod[t] = this->rod[t];
                    }
                    int moved = (rod[i] & 15);
                    newState.rod[i] =  (rod[i] >> 4);
                    newState.rod[j] = (rod[j] << 4) | moved;
                    ret.push_back(newState);
                }
            }
        }
        return ret;
    }
    bool operator< (const State& b)const {
        long long int sum1 = 0, sum2 = 0;
        for (int i = 0; i < 4; i++) {
            sum1 += this->rod[i];
        }
        for (int i = 0; i < 4; i++) {
            sum2 += b.rod[i];
        }
        return sum1 < sum2;
    }
    bool operator == (const State& rhs) const {
        for (int i = 0; i < 4; i++) {
            if (this->rod[i] != rhs.rod[i])
                return false;
        }
        return true;
    }
};
int sgn(int x) { if (!x) return 0; return x > 0 ? 1 : -1; }
int incr(int x) { if (x < 0) return x - 1; return x + 1; }
int bidirectional(State start, State finish) {
    map<State, int> c;
    queue<State> q;
    if (start == finish) return 0;
    q.push(start);
    c[start] = 1;
    q.push(finish);
    c[finish] = -1;
    while (!q.empty()) {
        State here = q.front();
        q.pop();
        vector<State> adjacent = here.getAdjacent();
        for (int i = 0; i < adjacent.size(); i++) {
            map<State, int>::iterator it = c.find(adjacent[i]);
            if (it == c.end()) {
                c[adjacent[i]] = incr(c[here]);
                q.push(adjacent[i]);
            }
            else if (sgn(it->second) != sgn(c[here]))
                return abs(it->second) + abs(c[here]) - 1;
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
        State finish;
        for (int i = n; i >= 1; i--) {
            finish.rod[3] |= i;
            if(i > 1)
                finish.rod[3] <<= 4;
        }
        State start;
        for (int i = 0; i < 4; i++) {
            int t;
            cin >> t;
            while (t--) {
                int k;
                cin >> k;
                start.rod[i] |= k;
                if (i > 1)
                    start.rod[i] <<= 4;
            }
        }
        cout << bidirectional(start, finish) << '\n';
    }
}