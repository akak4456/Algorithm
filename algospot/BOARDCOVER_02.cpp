//result:시간초과
#include <iostream>
#include <vector>
using namespace std;
int blockX[4][3] = { {0,0,-1},{0,0,1},{0,0,-1},{0,0,1} };
int blockY[4][3] = { {0,-1,0},{0,-1,0},{0,1,0},{0,1,0} };
int C;
int H, W;
char board[20][20];
int numOfCase;
void solve(int cnt) {
	if (cnt >= H * W) {
		bool canAdd = true;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (board[i][j] == '.') {
					canAdd = false;
					break;
				}
			}
			if (!canAdd)
				break;
		}
		if (canAdd)
			numOfCase++;
		return;
	}
	int startX = cnt % W;
	int startY = cnt / W;
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
			solve(cnt + 1);
			for (int j = 0; j < 3; j++) {
				board[startY + blockY[i][j]][startX + blockX[i][j]] = '.';
			}
		}
	}
	solve(cnt + 1);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		numOfCase = 0;
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> board[i][j];
			}
		}
		solve(0);
		cout << numOfCase << '\n';
	}
}