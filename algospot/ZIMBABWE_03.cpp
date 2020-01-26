//result:오답
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MOD = 1000000007;
string e, digits;
int n, m;
int cache[1 << 14][20][2];
int price(int index, int taken, int mod, int less) {
	if (index == n) {
	//less&&mod==0이어야 함
		return (mod == 0) ? 1 : 0;
	}
	int& ret = cache[taken][mod][less];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0;next < n;next++) {
		if ((taken & (1 << next)) == 0) {
			if (!less && e[index] < digits[next])
				continue;
			if (next > 0 && digits[next - 1] == digits[next] && (taken & (1 << next - 1)) == 0)
				continue;
			int nextTaken = taken | (1 << next);
			int nextMod = (mod * 10 + digits[next] - '0') % m;
			int nextLess = less || e[index] > digits[next];
			ret += price(index + 1, nextTaken, nextMod, nextLess);
			ret %= MOD;
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		memset(cache, -1, sizeof(cache));
		cin >> e >> m;
		digits = e;
		sort(digits.begin(), digits.end());
		n = digits.size();
		cout << price(0, 0, 0, 0) << endl;
	}
}