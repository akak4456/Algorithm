//result:틀렸습니다
#include <iostream>
using namespace std;
const int MAX_N = 1000 + 1;
int N, K;
int dp[MAX_N][MAX_N];
int main() {
	cin >> N >> K;
	for (int i = 1; i < MAX_N; i++)
		dp[i][1] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= i / 2; j++) {
			//cout << i << ' ' << j << endl;
			dp[i][j] = -1;
			for (int k = i - 2; k >= 1; k--) {
				dp[i][j] += dp[k][j - 1];
			}
		}
	}
	cout << dp[N][K] << '\n';
}