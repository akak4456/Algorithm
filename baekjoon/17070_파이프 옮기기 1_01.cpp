//result:맞았습니다!!
#include <iostream>
using namespace std;
int N;
int board[16][16];
int cnt = 0;
void solve(int endPointY, int endPointX, int direct) {
	//direct 0 = 가로 1 = 세로 2 = 대각선
	board[endPointY][endPointX] = 1;
	if (endPointY == N - 1 && endPointX == N - 1) {
		cnt++;
		return;
	}
	if (direct == 0) {
		if (endPointX + 1 < N && board[endPointY][endPointX+1] != 1 ) {
			board[endPointY][endPointX + 1] = 1;
			solve(endPointY, endPointX + 1, 0);
			board[endPointY][endPointX + 1] = 0;
		}
		if (endPointX + 1 < N && endPointY + 1 < N && board[endPointY + 1][endPointX + 1] != 1 && board[endPointY+1][endPointX] != 1 && board[endPointY ][endPointX+1] != 1) {
			board[endPointY + 1][endPointX + 1] = 1;
			board[endPointY + 1][endPointX] = 1;
			board[endPointY ][endPointX + 1] = 1;
			solve(endPointY + 1, endPointX + 1, 2);
			board[endPointY + 1][endPointX + 1] = 0;
			board[endPointY + 1][endPointX] = 0;
			board[endPointY][endPointX + 1] = 0;
		}
	}
	else if (direct == 1) {
		if (endPointY + 1 < N && board[endPointY+1][endPointX] != 1) {
			board[endPointY + 1][endPointX] = 1;
			solve(endPointY + 1, endPointX, 1);
			board[endPointY + 1][endPointX] = 0;
		}
		if (endPointX + 1 < N && endPointY + 1 < N && board[endPointY + 1][endPointX + 1] != 1 && board[endPointY + 1][endPointX] != 1 && board[endPointY][endPointX + 1] != 1) {
			board[endPointY + 1][endPointX + 1] = 1;
			board[endPointY + 1][endPointX] = 1;
			board[endPointY][endPointX + 1] = 1;
			solve(endPointY + 1, endPointX + 1, 2);
			board[endPointY + 1][endPointX + 1] = 0;
			board[endPointY + 1][endPointX] = 0;
			board[endPointY][endPointX + 1] = 0;
		}
	}
	else if (direct == 2) {
		if (endPointX + 1 < N && board[endPointY][endPointX + 1] != 1) {
			board[endPointY][endPointX + 1] = 1;
			solve(endPointY, endPointX + 1, 0);
			board[endPointY][endPointX + 1] = 0;
		}
		if (endPointY + 1 < N && board[endPointY + 1][endPointX] != 1) {
			board[endPointY + 1][endPointX] = 1;
			solve(endPointY + 1, endPointX, 1);
			board[endPointY + 1][endPointX] = 0;
		}
		if (endPointX + 1 < N && endPointY + 1 < N && board[endPointY + 1][endPointX + 1] != 1 && board[endPointY + 1][endPointX] != 1 && board[endPointY][endPointX + 1] != 1) {
			board[endPointY + 1][endPointX + 1] = 1;
			board[endPointY + 1][endPointX] = 1;
			board[endPointY][endPointX + 1] = 1;
			solve(endPointY + 1, endPointX + 1, 2);
			board[endPointY + 1][endPointX + 1] = 0;
			board[endPointY + 1][endPointX] = 0;
			board[endPointY][endPointX + 1] = 0;
		}
	}
	board[endPointY][endPointX] = 0;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	solve(0, 1, 0);
	cout << cnt << '\n';
}