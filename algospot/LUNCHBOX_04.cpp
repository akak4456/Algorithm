//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
pair<int, int> lunch[10000];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        for (int i = 0;i < n;i++) {
            cin >> lunch[i].second;
        }
        for (int i = 0;i < n;i++) {
            cin >> lunch[i].first;
            lunch[i].first = -lunch[i].first;
        }
        sort(lunch, lunch + n);
        int boilTime = 0;
        int eatTime = 0;
        for (int i = 0;i < n;i++) {
            boilTime += lunch[i].second;
            if (eatTime < boilTime+(-lunch[i].first)) {
                eatTime = boilTime + (-lunch[i].first);
            }
        }
        cout << eatTime << '\n';
    }
}