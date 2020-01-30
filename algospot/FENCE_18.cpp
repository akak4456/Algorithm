//result:시간초과
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int N;
int arr[20000];
int solve(int left, int right) {
    if (left == right)
        return arr[left];
    int mid = (left + right) / 2;
    int ret = -987654321;
    ret = max(ret, solve(left, mid));
    ret = max(ret, solve(mid + 1, right));
    int leftIdx = mid - 1;
    int rightIdx = mid;
    int leftH = arr[leftIdx];
    int rightH = arr[rightIdx];
    while (leftIdx >= 0 && rightIdx < N) {
        ret = max(ret, min(leftH, rightH) * (rightIdx - leftIdx + 1));
        if (leftH > rightH) {
            leftIdx--;
            leftH = arr[leftIdx];
        }
        else {
            rightIdx++;
            rightH = arr[rightIdx];
        }
    }
    while (leftIdx >= 0) {
        ret = max(ret, min(leftH, rightH) * (rightIdx - leftIdx + 1));
        leftIdx--;
        leftH = arr[leftIdx];
    }
    while (rightIdx < N) {
        ret = max(ret, min(leftH, rightH) * (rightIdx - leftIdx + 1));
        rightIdx++;
        rightH = arr[rightIdx];
    }
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
        cin >> N;
        for (int i = 0;i < N;i++) {
            cin >> arr[i];
        }
        cout << solve(0, N - 1) << '\n';
    }
}