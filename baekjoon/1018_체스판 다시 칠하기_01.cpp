//result:틀렸습니다
#include <iostream>
#include <cmath>
using namespace std;
char board[50][50];//y x
int brushCount(char tmp[8][8]) {
	int ret = 0;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (y - 1 >= 0) {
				if (tmp[y][x] == 'W' && tmp[y - 1][x] == 'W') {
					tmp[y - 1][x] = 'B';
					ret++;
				}
				if (tmp[y][x] == 'B' && tmp[y - 1][x] == 'B') {
					tmp[y - 1][x] = 'W';
					ret++;
				}
			}
			if (y + 1 < 8) {
				if (tmp[y][x] == 'W' && tmp[y + 1][x] == 'W') {
					tmp[y + 1][x] = 'B';
					ret++;
				}
				if (tmp[y][x] == 'B' && tmp[y + 1][x] == 'B') {
					tmp[y + 1][x] = 'W';
					ret++;
				}
			}
			if (x - 1 >= 0) {
				if (tmp[y][x] == 'W' && tmp[y][x - 1] == 'W') {
					tmp[y][x - 1] = 'B';
					ret++;
				}
				if (tmp[y][x] == 'B' && tmp[y][x - 1] == 'B') {
					tmp[y][x - 1] = 'W';
					ret++;
				}
			}
			if (x + 1 < 8) {
				if (tmp[y][x] == 'W' && tmp[y][x + 1] == 'W') {
					tmp[y][x + 1] = 'B';
					ret++;
				}
				if (tmp[y][x] == 'B' && tmp[y][x + 1] == 'B') {
					tmp[y][x + 1] = 'W';
					ret++;
				}
			}
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	int minBrush = 987654321;
	for (int startY = 0; startY <= M - 8;startY++) {
		for (int startX = 0; startX <= N - 8; startX++) {
			char tmp[8][8];
			for (int i = startY; i < startY + 8; i++) {
				for (int j = startX; j < startX + 8; j++) {
					tmp[i - startY][j - startX] = board[i][j];
				}
			}
			int ret = brushCount(tmp);
			if (ret < minBrush)
				minBrush = ret;
		}
	}
	cout << minBrush << endl;
}