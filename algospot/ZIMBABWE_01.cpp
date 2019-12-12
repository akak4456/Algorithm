//result:정답
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int c;
string e, digits;
int n,m;
int cache[1 << 14][20][2];
int price(int index, int taken, int mod, int less) {
	if (index == n) {
		return (less && mod == 0) ? 1 : 0;
	}
	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < n; next++) {
		if ((taken & (1 << next)) == 0) {
			if (!less && e[index] < digits[next])
				continue;
			if (next > 0 && digits[next - 1] == digits[next] && (taken & (1 << (next - 1))) == 0)
				continue;
			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less||e[index] > digits[next];
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> c;
	while (c--) {
		for (int i = 0; i < (1 << 14); i++) {
			for (int j = 0; j < 20; j++) {
				for (int k = 0; k < 2; k++) {
					cache[i][j][k] = -1;
				}
			}
		}
		cin >> e >> m;
		n = e.size();
		digits = e;
		sort(digits.begin(), digits.end());
		cout << price(0, 0, 0, 0) << endl;
	}
}