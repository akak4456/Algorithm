//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
 
int n, m;
vector<int> arr1;
vector<int> arr2;
 
int dp[102][102];
 
int jlis(int start1, int start2) {
    if (dp[start1+1][start2+1] != -1)
        return dp[start1+1][start2+1];
    int ret = 0, comp = 0;
    if (start1 == -1 && start2 != -1) {
        comp = arr2[start2];
    }
    else if (start1 != -1 && start2 == -1) {
        comp = arr1[start1];
    }
    else if(start1 != -1 && start2 != -1){
        comp = max(arr1[start1], arr2[start2]);
    }
    
    for (int i = start1 + 1; i < n; ++i)
        if ((start1 == -1 && start2 == -1) || comp < arr1[i])
            ret = max(ret, jlis(i, start2) + 1);
    for (int i = start2 + 1; i < m; ++i)
        if ((start1 == -1 && start2 == -1) || comp < arr2[i])
            ret = max(ret, jlis(start1, i) + 1);
    dp[start1+1][start2+1] = ret;
    return ret;
}
 
int main() {
    int T, temp;
    cin >> T;
    while (T--) {
        arr1.clear();
        arr2.clear();
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
            arr1.push_back(temp);
        }
        for (int i = 0; i < m; ++i) {
            cin >> temp;
            arr2.push_back(temp);
        }
        
        int ret = 1;
        ret = max(ret, jlis(-1, -1));
        cout << ret << endl;
    }
    return 0;
}