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
using namespace std;
vector<string> product;
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
    if (cache[idx][capacity] == cache[idx + 1][capacity]) {
        recover(idx + 1, capacity);
    }
    else if (cache[idx][capacity] == cache[idx + 1][capacity - V[idx]] + WANT[idx]) {
        result.push_back(product[idx]);
        recover(idx + 1, capacity - V[idx]);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        product.clear();
        result.clear();
        memset(cache, -1, sizeof(cache));
        cin >> N >> W;
        product.resize(N);
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