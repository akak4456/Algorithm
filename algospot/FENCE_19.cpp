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
    //cout << "ret1:" << ret << " " << left << " " << mid << endl;
    ret = max(ret, solve(mid + 1, right));
    //cout << "ret2:" << ret <<" "<< left << " " << mid<< endl;
    int leftIdx = mid;
    int rightIdx = mid+1;
    int minH = min(arr[leftIdx], arr[rightIdx]);
    while (leftIdx >= 0 && rightIdx < N) {
        ret = max(ret, minH * (rightIdx - leftIdx + 1));
       // if(left == 0 &&  right == N-1)
       // cout << leftH << " " << rightH << " "<< min(leftH, rightH) * (rightIdx - leftIdx + 1) << endl;
        if (arr[leftIdx] > arr[rightIdx]) {
            leftIdx--;
            if (leftIdx < 0)
                break;
            minH = min(minH, arr[leftIdx]);
        }
        else {
            rightIdx++;
            if (rightIdx >= N)
                break;
        }
        minH = min(minH, arr[leftIdx]);
        minH = min(minH, arr[rightIdx]);
    }
    while (leftIdx >= 0) {
        ret = max(ret, minH * (rightIdx - leftIdx + 1));
        leftIdx--;
        if (leftIdx < 0)
            break;
        minH = min(minH, arr[leftIdx]);
        minH = min(minH, arr[rightIdx]);
    }
    while (rightIdx < N) {
        ret = max(ret, minH * (rightIdx - leftIdx + 1));
        rightIdx++;
        if (rightIdx >= N)
            break;
        minH = min(minH, arr[leftIdx]);
        minH = min(minH, arr[rightIdx]);
    }
   // cout << "ret:" << ret << endl;
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