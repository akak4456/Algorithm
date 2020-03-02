//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
int n;
int dp[100][100];
string wildcard, src;
int solve(int idx1, int idx2) {
   // cout << idx1 << ' ' << idx2 << endl;
    //와일드카드 문자열 idx1 파일 문자열 idx2일때 이건 과연?
    if (idx1 >= wildcard.size()) {
        if (idx2 >= src.size())
            return 1;
        return 0;
    }
    if (idx2 >= src.size()) {
        if (idx1 >= wildcard.size())
            return 1;
        if (idx1 == wildcard.size() - 1 && wildcard[idx1] == '*')
            return 1;
        return 0;
    }
    int& ret = dp[idx1][idx2];
    if (ret != -1) return ret;
    ret = 0;
    if (wildcard[idx1] == '*') {
        for (int nextIdx = idx2; nextIdx <= src.size(); nextIdx++) {
            if (solve(idx1 + 1, nextIdx) == 1)
                ret = 1;
        }
        return ret;
    }
    else if (wildcard[idx1] == '?') {
        ret = solve(idx1 + 1, idx2 + 1);
        return ret;
    }
    else {
        if (wildcard[idx1] == src[idx2])
            ret = solve(idx1+1,idx2+1);
        return ret;
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
        cin >> wildcard;
        cin >> n;
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            memset(dp, -1, sizeof(dp));
            cin >> src;
            if (solve(0, 0) == 1)
                ans.push_back(src);
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << endl;
    }
}