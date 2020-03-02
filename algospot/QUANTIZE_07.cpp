//result:시간초과
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
const int INF = 987654321;
int n, s;
int A[101];
int cache[101][11];
/*
전에는 숫자 n이 from부터 양자화 된다고 가정하고 풀었다. 그랬더니 시간초과가 뜬다.
그래서 cache[from][part]로 푼다.
part는 10개 이하이기 때문이다.
=>숫자를 기준으로 하는 것이 아니라 PART를 기준으로 한다.
*/
int minError(int lo, int hi) {
    int ret = INF;
    for (int num = 1; num <= 1000; num++) {
        int sum = 0;
        for (int i = lo; i <= hi; i++) {
            sum += (A[i] - num) * (A[i] - num);
        }
        ret = min(ret, sum);
    }
    return ret;
}
int quantize(int from, int parts) {
    if (from == n) return 0;
    if (parts == 0) return INF;
    int& ret = cache[from][parts];
    if (ret != -1) return ret;

    ret = INF;

    for (int partSize = 1; from + partSize <= n; partSize++)
        ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, parts - 1));

    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        memset(cache, -1, sizeof(cache));
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> A[i];
        sort(A, A + n);
        cout << quantize(0,s) << '\n';
    }
}