//result:정답
#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int cache[101];
int cache2[101];
int solve(int n) {
	if (n <= 1)
		return cache[n] = 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	return ret = (solve(n - 1) + solve(n - 2))%MOD;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	cout<<fixed;
	cout.precision(10);
	while (C--) {
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		int ans = solve(n);
		if (n % 2 == 0) {
			ans = ((ans%MOD)-(cache[n/2]%MOD) + MOD)%MOD;
			ans = ((ans % MOD) - (cache[n / 2 - 1] % MOD) + MOD) % MOD;
		}
		else {
			ans = ((ans % MOD) - (cache[n / 2] % MOD) + MOD) % MOD;
		}
		cout << ans << '\n';
	}
}