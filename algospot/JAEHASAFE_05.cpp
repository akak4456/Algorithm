//result:오답
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
vector<int> parPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[matched] == N[begin + matched]) {
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
int kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> pi = parPartialMatch(N);
    int begin = 0, matched = 0;
    while (begin <= n - m) {
        if (matched < m && H[begin + matched] == N[matched]) {
            matched++;
            if (matched == m)
                return begin;
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
    return -1;//말이 안되는 값
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        int N;
        cin >> N;
        int ans = 0;
        string src1, src2;
        cin >> src1;
        for (int i = 0; i < N; i++) {
            cin >> src2;
            if (i % 2 == 0) {
                //시계방향
                ans += src2.size()-kmpSearch(src1 + src1, src2);
            }
            else {
                //반시계방향
                ans += kmpSearch(src1 + src1, src2);
            }
            src1 = src2;
        }
        cout << ans << '\n';
    }
}