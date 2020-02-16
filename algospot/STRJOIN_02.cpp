//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>
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
        priority_queue<int> pq;
        for (int i = 0;i < n;i++) {
            int t;
            cin >> t;
            pq.push(-t);
        }
        int cost = 0;
        while (pq.size() >= 2) {
            int sumOfTwo = -pq.top();
            //cout << "sumOfTwo1: " << sumOfTwo << endl;
            pq.pop();
            sumOfTwo += -pq.top();
          //  cout << "sumOfTwo2: " << sumOfTwo << endl;
            pq.pop();
            cost += sumOfTwo;
            pq.push(-sumOfTwo);
        }
        cout << cost << '\n';
    }
}