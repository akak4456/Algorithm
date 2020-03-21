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
int maxOverlap(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<int> pi = getPartialMatch(b);
    int begin = 0, matched = 0;
    while (begin < n) {
        if (matched < m && a[begin + matched] == b[matched]) {
            ++matched;
            if (begin + matched == n)
                return matched;
        }
        else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return 0;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        string src;
        cin >> src;
        string reverse_src = src;
        reverse(reverse_src.begin(), reverse_src.end());
        cout << src.size()*2 - maxOverlap(src,reverse_src) << '\n';
    }
}