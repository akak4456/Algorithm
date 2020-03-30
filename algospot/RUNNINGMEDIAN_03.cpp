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
#include <map>
#include <cstdint> //or <stdint.h>
#include <limits>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        long long int A = 1983;
        int n,a,b;
        cin >> n >> a >> b;
        priority_queue<int, vector<int>, less<int> >maxHeap;
        priority_queue<int, vector<int>, greater<int> >minHeap;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (maxHeap.size() == minHeap.size()) {
                maxHeap.push(A);
            }
            else {
                minHeap.push(A);
            }
            if (!maxHeap.empty() && !minHeap.empty()&&maxHeap.top() > minHeap.top()) {
                int t1 = maxHeap.top();
                int t2 = minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(t2);
                minHeap.push(t1);
            }
            A = (A% 20090711 * a + b) % 20090711;
          //  cout << A << endl;
            sum += maxHeap.top()%20090711;
            //cout << sum << endl;
            sum %= 20090711;
        }
        cout << sum % 20090711 << '\n';
    }
}