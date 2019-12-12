//result:시간 초과
#include <iostream>
#include <vector>
using namespace std;
vector<int> coin;
int solve(int remain,int maxCoin) {
	int ret = 0;
	for (int i = 0; i < coin.size(); i++) {
		if (maxCoin >= coin[i]) {
			if (remain - coin[i] == 0) {
				ret += 1;
			}
			else if (remain - coin[i] > 0) {
				ret += solve(remain - coin[i], coin[i]);
			}
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	cout << solve(k,k) << '\n';
}