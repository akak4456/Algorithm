//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501];
int cost[501];
int sum[501];
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> cost[i];
			sum[i] = sum[i - 1] + cost[i];
		}
		for (int d = 1; d < k; d++) {
			for (int tx = 1; tx + d <= k; tx++) {
				int ty = tx + d;
				dp[tx][ty] = 987654321;
				for (int mid = tx; mid < ty; mid++) {
					dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
				}
			}
		}
		cout << dp[1][k] << '\n';
	}
}