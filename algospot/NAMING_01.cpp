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
vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else {
            if (matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}
vector<int> solve(const string& N) {
    vector<int> pi = getPartialMatch(N);
    int k = N.size();
    vector<int> ret;
    while (k > 0) {
        ret.push_back(k);
        k = pi[k - 1];
    }
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    //cin >> test_case;
    string src1, src2;
    cin >> src1 >> src2;
    vector<int> ans = solve(src1 + src2);
    sort(ans.begin(), ans.end());
    for (int t : ans) {
        cout << t << ' ';
    }
    cout << '\n';
}