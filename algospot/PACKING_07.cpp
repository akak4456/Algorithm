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
string product[100];
vector<string> result;
int cache[100][1001];
int N,W;
int V[100], WANT[100];
int solve(int idx, int capacity) {
    if (idx == N)
        return 0;
    int& ret = cache[idx][capacity];
    if (ret != -1) return ret;
    ret = solve(idx + 1, capacity);
    if (capacity >= V[idx])
        ret = max(ret, solve(idx + 1, capacity - V[idx]) + WANT[idx]);
    return ret;
}
void recover(int idx, int capacity) {
    //cout << idx << ' ' << capacity << ' '<<cache[idx][capacity]<<endl;
    if (idx == N)
        return;
    if (solve(idx,capacity)== solve(idx+1,capacity)) {
        recover(idx + 1, capacity);
    }
    else if (solve(idx,capacity) == solve(idx + 1, capacity - V[idx]) + WANT[idx]) {
        result.push_back(product[idx]);
        recover(idx + 1, capacity - V[idx]);
    }
    /*
    if (solve(idx,capacity) == solve(idx + 1, capacity - V[idx]) + WANT[idx]) {
        result.push_back(product[idx]);
        recover(idx + 1, capacity - V[idx]);
    }
    이렇게 만들면 틀린다 왜냐하면 중복해서 계산되기 때문에
    */
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        result.clear();
        memset(cache, -1, sizeof(cache));
        cin >> N >> W;
        for (int i = 0; i < N; i++) {
            cin >> product[i] >> V[i] >> WANT[i];
        }
     
        cout << solve(0, W) << ' ';
        recover(0, W);
        cout << result.size() << '\n';
        for (string item : result) {
            cout << item << '\n';
        }
    }
}