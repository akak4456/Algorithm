//result:틀렸습니다
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main() {
	std::ios::sync_with_stdio(false);
	string source, destination;
	cin >> source >> destination;
	int sz1 = source.size();
	int sz2 = destination.size();
	for (int i = 1; i <= sz1; i++) {
		for (int j = 1; j <= sz2; j++) {
			int tmp = dp[i][j - 1];
			if (source[i] == destination[j]) {
				tmp++;
			}
			dp[i][j] = max(dp[i - 1][j], tmp);
		}
	}
	cout << dp[sz1][sz2] << '\n';
}