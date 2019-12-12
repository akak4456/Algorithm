//result:맞았습니다!!
#include <iostream>
#include <vector>
using namespace std;
vector<int> coin;
int dp[10001];
int main() {
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	dp[0] = 1;
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= k; i++) {
		
			int preIdx = i - coin[j];
			if (preIdx >= 0) {
				dp[i] += dp[preIdx];
			}
		}
	}
	cout << dp[k] << '\n';
}