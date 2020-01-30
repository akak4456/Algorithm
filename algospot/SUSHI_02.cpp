//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
int n, m;
int cache[201];
int price[20];
int pref[20];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
        memset(cache, 0, sizeof(cache));
        cin >> n >> m;
        m /= 100;
        for (int i = 0;i < n;i++) {
            cin >> price[i] >> pref[i];
            price[i] /= 100;
        }
        for (int budget = 0;budget <= m;budget++) {
            for (int dish = 0;dish < n;dish++) {
                if (budget >= price[dish]) {
                    cache[budget%201] = max(cache[budget % 201], cache[(budget - price[dish]+201)%201] + pref[dish]);
                }
            }
        }
        cout << cache[m%201] << '\n';
    }
}