//result:정답
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int C, N;
int tri[100][100];
int cache[100][100];
int solve(int y, int x) {
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;
	if (y == N - 1)
		return ret = tri[y][x];
	ret = 0;
	if (y < N - 1) {
		ret = max(ret, tri[y][x] + solve(y+1,x));
		ret = max(ret, tri[y][x] + solve(y+1, x + 1));
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> tri[i][j];
			}
		}
		cout << solve(0, 0) << '\n';
	}
}