//result:맞았습니다!!
#include <iostream>
using namespace std;
const int MOD = 1000000003;
const int MAX_N = 1000 + 1;
int N, K;
int dp[MAX_N][MAX_N];
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int i = 2; i <= N-1; i++) {
		for (int j = 2; j <= N-1; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << (dp[N-1][K]+dp[N-3][K-1])%MOD << '\n';
}