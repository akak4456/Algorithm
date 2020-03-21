//result:시간초과
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
struct Comparator {
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t):group(_group),t(_t) {
    }
    bool operator()(int a, int b) {
        if (group[a] != group[b]) return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};
vector<int> getSuffixArray(const string& s) {
    int n = s.size();
    int t = 1;
    vector<int> group(n + 1);
    for (int i = 0; i < n; i++) group[i] = s[i];
    group[n] = -1;
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;
    while (t < n) {
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        t *= 2;
        if (t >= n) break;
        vector<int> newGroup(n + 1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (compareUsing2T(perm[i - 1], perm[i])) {
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            }
            else {
                newGroup[perm[i]] = newGroup[perm[i - 1]];
            }
        }
        group = newGroup;
    }
    return perm;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        int K;
        string src;
        
        cin >> K >> src;
        int n = src.size();
        vector<int> a = getSuffixArray(src);
        vector<int> oldGroup(n,0);
        int ans = 0;
        for (int idx = 0; idx < src.size(); idx++) {
            int cnt = 1;
            vector<int> newGroup(n);
            newGroup[a[0]] = 0;
            for (int i = 1; i < a.size(); i++) {
                int pos1 = a[i - 1] + idx;
                int pos2 = a[i] + idx;
                if (oldGroup[a[i - 1]] == oldGroup[a[i]] && pos1 < src.size() && pos2 < src.size()&&src[pos1] == src[pos2]) {
                    cnt++;
                    newGroup[a[i]] = newGroup[a[i - 1]];
                }
                else {
                    if (cnt >= K) {
                       ans = max(ans, idx + 1);
                    }
                    cnt = 1;
                    newGroup[a[i]] = newGroup[a[i - 1]] + 1;
                }
              //  cout << aGroup[a[i]] << endl;
            }
            oldGroup = newGroup;
        }
        cout << ans << '\n';
    }
}