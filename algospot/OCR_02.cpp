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
const int MAX_M = 500 + 1;
int m, q;
string src[MAX_M];
double T[MAX_M][MAX_M];
double M[MAX_M][MAX_M];
double cache[MAX_M][MAX_M];
int matched[MAX_M];
int n;
vector<string> result;
double solve(int ch, int idx) {
   // cout << ch << ' ' << idx << endl;
    if (idx == n) {
        return cache[ch][idx]=0;
    }
    double& ret = cache[ch][idx];
    if (ret != 1) return ret;
    for (int i = 1; i <= m; i++) {
        if (ret == 1) {
            ret = solve(i, idx + 1) + T[ch][i] + M[i][matched[idx + 1]];
        }
        else {
            ret = max(ret, solve(i, idx + 1) + T[ch][i] + M[i][matched[idx + 1]]);
        }
    }
    return ret;
}
void reconstruct(int ch, int idx) {
  //  cout << ch << ' ' << idx << endl;
    for (int i = 1; i <= m; i++) {
        if (cache[ch][idx] == cache[i][idx + 1] + T[ch][i] + M[i][matched[idx + 1]]) {

           // cout << src[i] << endl;
            result.push_back(src[i]);
            reconstruct(i, idx + 1);
            return;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> q;
    for (int i = 1; i <= m; i++)
        cin >> src[i];
    for (int i = 0; i <= m; i++){
        for (int j = 1; j <= m; j++) {
            cin >> T[i][j];
            T[i][j] = log(T[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> M[i][j];
            M[i][j] = log(M[i][j]);
        }
    }
    while (q--) {
        for (int i = 0; i < MAX_M; i++)
            for (int j = 0; j < MAX_M; j++)
                cache[i][j] = 1;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string str;
            cin >> str;
            for (int j = 1; j <= m; j++) {
                if (src[j] == str) {
                    matched[i] = j;
                    break;
                }
            }
        }
        solve(0, 0);
        result.clear();
        reconstruct(0, 0);
       // cout << solve(0, 0) << '\n';
        for (string res : result) {
            cout << res << ' ';
        }
        cout << '\n';
    }
}