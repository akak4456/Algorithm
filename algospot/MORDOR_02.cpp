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
const int MAX = 987654321;
struct RMQ {
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n * 4);
        init(array, 0, n - 1, 1);
    }
    int init(const vector<int>& array, int left, int right, int node) {
        if (left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) return MAX;
        if (left <= nodeLeft && nodeRight <= right)
            return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        if (index < nodeLeft || nodeRight < index)
            return rangeMin[node];
        if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }
    int update(int index, int newValue) {
        return update(index, newValue, 1, 0, n - 1);
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr;
        vector<int> arr2;
        arr.resize(n);
        arr2.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr2[i] = -arr[i];
        }
        RMQ minRange(arr);
        RMQ maxRange(arr2);
        for (int i = 0; i < q; i++) {
            int left, right;
            cin >> left >> right;
            cout << -maxRange.query(left, right) -minRange.query(left, right)  << '\n';
        }
    }
}