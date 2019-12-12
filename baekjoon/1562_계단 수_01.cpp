//result:맞았습니다!!
#include <iostream>
using namespace std;
const int FULL = (1 << 10) - 1;
const int MOD = 1000000000;
long long int dp[101][10][(1 << 10)];
int main() {
	int N;
	cin >> N;
	for (int j = 1; j <= 9; j++) {
		dp[1][j][(1 << j)] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= FULL; k++) {
				int mask = 1 << j;
				if (j == 0) {
					dp[i][j][k | mask] += dp[i - 1][j+1][k];
					dp[i][j][k | mask] %= MOD;
				}
				else if (j == 9) {
					dp[i][j][k | mask] += dp[i - 1][j - 1][k];
					dp[i][j][k | mask] %= MOD;
				}
				else {
					dp[i][j][k | mask] += dp[i - 1][j + 1][k];
					dp[i][j][k | mask] %= MOD;
					dp[i][j][k | mask] += dp[i - 1][j - 1][k];
					dp[i][j][k | mask] %= MOD;
				}
			}
		}
	}
	long long int sum = 0;
	for (int j = 0; j <= 9; j++) {
		sum += dp[N][j][FULL];
		sum %= MOD;
	}
	cout << sum % MOD;
}