//result:정답
#include <iostream>
#include <cstring>
using namespace std;
int board[100][100];
int cache[100][100];
int C, N;
int solve(int y, int x) {
	if (x < 0 || x >= N || y < 0 || y >= N) return 0;
	if (y == N - 1 && x == N - 1) return 1;
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;
	if (solve(y + board[y][x], x) == 1) {
		return ret = 1;
	}
	if (solve(y, x + board[y][x]) == 1) {
		return ret = 1;
	}
	return ret = 0;
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
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}
		if (solve(0, 0) == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}