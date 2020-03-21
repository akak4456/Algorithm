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
int commonPrefix(const string& s, int i, int j) {
    int k = 0;
    while (i < s.size() && j < s.size() && s[i] == s[j]) {
        i++;
        j++;
        k++;
    }
    return k;
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
        vector<int> a = getSuffixArray(src);
        int ans = 0;
        for (int i = 0; i + K - 1 < a.size(); i++) {
             ans = max(ans, commonPrefix(src, a[i], a[i + K - 1]));
        }
        cout << ans << '\n';
    }
}