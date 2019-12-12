//result:정답
#include <iostream>
using namespace std;

int C;
int n;
const int MOD = 10 * 1000 * 1000;
int cache[101][101];

int poly(int n, int first) {
	if (n == first) {
		return 1;
	}
	int & ret = cache[n][first];
	if (ret != -1) return ret;
	ret = 0;
	for (int second = 1; second <= n - first; second++) {
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}
int main() {
	cin >> C;
	while (C--) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				cache[i][j] = -1;
			}
		}
		cin >> n;
		int result = 0;
		for (int i = 1; i <= n; i++) {
			result += poly(n, i);
			result %= MOD;
		}
		cout << result << endl;
	}
}