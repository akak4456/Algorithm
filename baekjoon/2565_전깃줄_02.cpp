//result:틀렸습니다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> > rope;
int dp[501];
int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		rope.push_back(make_pair(t1, t2));
	}
	sort(rope.begin(), rope.end());
	int max_len = -1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (rope[i].second > rope[j].second) {
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
		if (max_len < dp[i])
			max_len = dp[i];
	}
	cout << (n - max_len) << '\n';
}