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
double n, p;
int m;
double newP[121];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(10);
    int test_case;
  //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        cin >> n >> m >> p;
        newP[0] = (1 + p / 1200.0);
        double sumP = newP[0];
        for (int i = 1; i <= m; i++) {
            newP[i] = newP[i - 1] * (1 + p / 1200.0);
            if (i < m)
                sumP += newP[i];
        }
        cout << (n * newP[m]) / sumP << '\n';
    }
}