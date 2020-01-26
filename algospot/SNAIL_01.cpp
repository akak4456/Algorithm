//result:정답
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_M = 1000;
const int MAX_N = 1000;
int n, m;
double cache[MAX_M + 1][2 * MAX_N + 1];
double climb(int days, int climbed) {
	if (days == m) return climbed >= n ? 1 : 0;
	double& ret = cache[days][climbed];
	if (ret != -1) return ret;
	return ret = climb(days + 1, climbed + 1) * 0.25 + climb(days + 1, climbed + 2) * 0.75;
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
		for (int i = 0; i < MAX_M + 1; i++) {
			for (int j = 0; j < 2 * MAX_N + 1; j++) {
				cache[i][j] = -1;
			}
		}
		cin >> n >> m;
		cout << climb(0, 0) << '\n';
	}
}