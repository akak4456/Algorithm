//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
        int russian[100];
        pair<int, bool> korean[100];
        int n;
        cin >> n;
        for (int i = 0;i < n;i++) {
            cin >> russian[i];
        }
        for (int i = 0;i < n;i++) {
            cin >> korean[i].first;
            korean[i].second = false;
        }
        sort(korean, korean + n);
        int cnt = 0;
        for (int russianIdx = 0;russianIdx < n;russianIdx++) {
            bool win = false;
            int startIdx = -1;
            for (int koreanIdx = 0;koreanIdx < n;koreanIdx++) {
                if (!korean[koreanIdx].second) {
                    if (startIdx == -1) {
                        startIdx = koreanIdx;
                    }
                    if (korean[koreanIdx].first >= russian[russianIdx]) {
                        win = true;
                        korean[koreanIdx].second = true;
                        break;
                    }
                }
            }
            if (win)
                cnt++;
            else
                korean[startIdx].second = true;
        }
        cout << cnt << '\n';
    }
}