//result:정답
#include <iostream>
#include <vector>
using namespace std;
int blockX[4][3] = { {0,0,1},{0,1,1},{0,0,1},{0,0,-1} };
int blockY[4][3] = { {0,1,0},{0,0,1},{0,1,1},{0,1,1} };
int C;
int H, W;
char board[20][20];
int solve() {
	int startX = -1, startY = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == '.') {
				startX = j;
				startY = i;
				break;
			}
		}
		if (startY != -1)
			break;
	}
	if (startY == -1)
		return 1;
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		bool canPut = true;
		for (int j = 0; j < 3; j++) {
			if (startX + blockX[i][j] < 0 || startX + blockX[i][j] >= W || startY + blockY[i][j] < 0 || startY + blockY[i][j] >= H || board[startY + blockY[i][j]][startX + blockX[i][j]] != '.') {
				canPut = false;
				break;
			}
		}
		if (canPut) {
			for (int j = 0; j < 3; j++) {
				board[startY + blockY[i][j]][startX + blockX[i][j]] = '#';
			}
			ret += solve();
			for (int j = 0; j < 3; j++) {
				board[startY + blockY[i][j]][startX + blockX[i][j]] = '.';
			}
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
			}
		}
		cout << solve() << '\n';
	}
}