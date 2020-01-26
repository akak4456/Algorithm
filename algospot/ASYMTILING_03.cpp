//result:정답
#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int cache[101];
int cache2[101];
int tiling(int width) {
	if (width <= 1) return 1;
	int& ret = cache[width];
	if (ret != -1) return ret;
	return ret = (tiling(width - 2) + tiling(width - 1)) % MOD;
}
int asymmetric2(int width) {
	if (width <= 2) return 0;
	int& ret = cache2[width];
	if (ret != -1) return ret;
	ret = 0;
	ret = (ret+asymmetric2(width - 2))%MOD;
	ret = (ret + asymmetric2(width - 4)) % MOD;
	ret = (ret + tiling(width - 3)) % MOD;
	ret = (ret + tiling(width - 3)) % MOD;
	return ret;
}
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
		memset(cache2, -1, sizeof(cache2));
		int n;
		cin >> n;
		cout << asymmetric2(n) << '\n';
	}
}