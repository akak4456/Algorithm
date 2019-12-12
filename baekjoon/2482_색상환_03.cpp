//result:맞았습니다!!
/*
처음부터 원형으로 고려:이유 dp[3][2] = 0
cf)
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
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 2; j <= N - 1; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % MOD << '\n';
}
이것은 선형으로 고려하다가 마지막에 원형으로 고려한 것이다 실제로 dp의 값이 다르다.
*/
#include <iostream>
using namespace std;
const int MOD = 1000000003;
const int MAX_N = 1000 + 1;
int N, K;
int dp[MAX_N][MAX_N];
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		dp[i][1] = i;
	for (int i = 4; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}
	cout << dp[N][K] << '\n';
}