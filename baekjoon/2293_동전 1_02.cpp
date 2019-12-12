//result:틀렸습니다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> coin;
int dp[100001];
int main() {
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < coin.size(); j++) {
			int preIdx = i - coin[j];
			if (preIdx >= 0) {
				if (preIdx > coin[j]) {
					for (int t = 0; t < coin.size(); t++) {
						if (coin[t] == preIdx)
							break;
						else if (t == coin.size() - 1)
							dp[i] += dp[preIdx];
					}
				}
				else {
					dp[i] += dp[preIdx];
				}
			}
		}
	}
	cout << dp[k] << '\n';
}