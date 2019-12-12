//result:정답
#include <iostream>
using namespace std;

int C;
int n;
int cache[101]; 
const int MOD = 1000000007;
int tiling(int n) {
	if (n <= 1) {
		return 1;
	}
	int& ret = cache[n];
	if (ret != -1) return ret;
	ret = (tiling(n - 1) + tiling(n - 2))%MOD;
	return ret;
}
int solve(int n) {
	if (n % 2 == 1) {
		return (tiling(n)-tiling(n / 2) + MOD) % MOD;
	}
	int ret = tiling(n);
	ret = (ret - tiling(n / 2) + MOD) % MOD;
	ret = (ret - tiling(n / 2-1) + MOD) % MOD;
	return ret;
}
int main() {
	cin >> C;
	while (C--) {
		for (int i = 0; i < 101; i++) {
			cache[i] = -1;
		}
		cin >> n;
		cout << solve(n) << endl;
	}
}