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
using namespace std;
struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) :tree(n + 1) {}
    int sum(int pos) {
        pos++;
        int ret = 0;
        while (pos > 0) {
          //  cout <<"pos:"<< pos << endl;
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos, int val) {
        pos++;
        while (pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};
long long countMoves(const vector<int>& A) {
    FenwickTree tree(1000000);
    long long ret = 0;
    for (int i = 0; i < A.size(); i++) {
        ret += tree.sum(1000000 - 1) - tree.sum(A[i]);
        tree.add(A[i], 1);
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
        int n;
        cin >> n;
        vector<int> A;
        A.resize(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << countMoves(A) << '\n';
    }
}