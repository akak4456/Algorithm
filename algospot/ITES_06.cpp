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
int N, K;
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        int K, N;
        cin >> K >> N;
        queue<int> q;
        long long int A0 = 1983;
        long long int A1 = (A0 * 214013 + 2531011) % (1ull << 32);
        int sum = 0;
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            int signal = A0 % 10000 + 1;
            q.push(signal);
            sum += signal;
            if (sum > K) {
                while (!q.empty() && sum > K) {
                    sum -= q.front();
                    q.pop();
                }
            }
            if (sum == K)
                cnt++;
            A0 = A1;
            A1 = (A0 * 214013 + 2531011) % (1ull << 32);
        }
        cout << cnt << '\n';
    }
}