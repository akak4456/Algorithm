//result:정답
#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1000000007;
int cache[101];
int tiling(int n) {
	if (n < 0)
		return 0;
	int& ret = cache[n];
	if (ret != -1)
		return ret;
	if (n == 0 || n == 1) {
		return ret = 1;
	}
	return ret = (tiling(n - 1)%MOD + tiling(n - 2)%MOD)%MOD;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	while (C--) {
		int n;
		memset(cache, -1, sizeof(cache));
		cin >> n;
		cout << tiling(n) << '\n';
	}
}