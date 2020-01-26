//result:정답
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_VIL = 50 + 1;
const int MAX_DAY = 100 + 1;
int matrix[MAX_VIL][MAX_VIL];
double cache[MAX_VIL][MAX_DAY];
int sz;
double solve(int n, int d) {
	if (d == 0)
		return cache[n][d] == -1 ? 0 : cache[n][d];
	double& ret = cache[n][d];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < sz; i++) {
		if (matrix[i][n] == 1) {
			double sum = 0;
			for (int j = 0; j < sz; j++) {
				sum += matrix[i][j];
			}
			sum = 1.0 / sum;
			ret += solve(i, d - 1) * sum;
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << fixed;
	cout.precision(10);
	int C;
	cin >> C;
	while (C--) {
		for (int i = 0; i < MAX_VIL; i++)
			for (int j = 0; j < MAX_DAY; j++)
				cache[i][j] = -1;
		int d, p;
		cin >> sz >> d >> p;
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				cin >> matrix[i][j];
		cache[p][0] = 1;
		for (int i = 0; i < sz; i++)
			solve(i, d);
		int t;
		cin >> t;
		while (t--) {
			int query;
			cin >> query;
			cout << cache[query][d] << ' ';
		}
		cout << '\n';
	}
}