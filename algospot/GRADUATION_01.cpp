//result:정답
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAXN = 12;
int c;
int n, k, m, l;
int prerequisite[MAXN];
int classes[10];
int cache[10][1 << MAXN];
int bitCount(int n) {
	int c = 0;
	while (n > 0) {
		if (n % 2 == 1)
			c++;
		n /= 2;
	}
	return c;
}
int graduate(int semester, int taken) {
	if (bitCount(taken) >= k) return 0;
	if (semester == m) return INF;

	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF;
	int canTake = (classes[semester] & ~taken);
	for (int i = 0; i < n; i++)
		if ((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
			canTake &= ~(1 << i);
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (bitCount(take) > l) continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> c;
	while (c--) {
		for (int i = 0; i < MAXN; i++)
			prerequisite[i] = 0;
		for (int i = 0; i < 10; i++) {
			classes[i] = 0;
			for (int j = 0; j < (1 << MAXN); j++)
				cache[i][j] = -1;
		}
		cin >> n >> k >> m >> l;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			while (t--) {
				int t2;
				cin >> t2;
				prerequisite[i] |= (1 << t2);
			}
		}
		for (int i = 0; i < m; i++) {
			int t;
			cin >> t;
			while (t--) {
				int t2;
				cin >> t2;
				classes[i] |= (1 << t2);
			}
		}
		int ans = graduate(0, 0);
		if (ans == INF)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << graduate(0, 0) << endl;
	}
}