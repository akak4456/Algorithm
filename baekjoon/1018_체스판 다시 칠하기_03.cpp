//result:맞았습니다!!
#include <iostream>
#include <cmath>
using namespace std;
char board[50][50];//y x
int brushCount(int startX,int startY) {
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int x = startX + i;
			int y = startY + j;
			if (x == startX && y == startY)continue;
			if ((i + j) % 2 == 0 && board[startY][startX] != board[y][x])
				ret++;
			if ((i + j) % 2 == 1 && board[startY][startX] == board[y][x])
				ret++;
		}
	}
	int ret2 = 1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int x = startX + i;
			int y = startY + j;
			if (x == startX && y == startY)continue;
			if ((i + j) % 2 == 0 && board[startY][startX] == board[y][x])
				ret2++;
			if ((i + j) % 2 == 1 && board[startY][startX] != board[y][x])
				ret2++;
		}
	}
	if (ret < ret2)
		return ret;
	else
		return ret2;
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
	for (int startY = 0; startY <= N - 8;startY++) {
		for (int startX = 0; startX <= M - 8; startX++) {
			int ret = brushCount(startX,startY);
			//cout << ret << endl;
			if (ret < minBrush)
				minBrush = ret;
		}
	}
	cout << minBrush << endl;
}