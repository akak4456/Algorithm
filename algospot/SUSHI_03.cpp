//result:정답
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m;
int p[20];
int f[20];
int cache[20001];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        cin >> n >> m;
        m /= 100;
        for (int i = 0; i < n; i++) {
            cin >> p[i] >> f[i];
            p[i] /= 100;
        }
        memset(cache, 0, sizeof(cache));
        for (int money = 0; money <= m; money++) {
            for (int idx = 0; idx < n; idx++) {
                if (money - p[idx] >= 0) {
                    cache[money % 20001] = max(cache[money % 20001], cache[(money - p[idx]) % 20001] + f[idx]);
                }
            }
        }
        cout << cache[m % 20001] << '\n';
    }
}