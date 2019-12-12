//result:정답
#include <iostream>
#include <vector>
using namespace std;
int C, H, W;
const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
int boardcover(bool board[20][20]) {
	//true 덮인것 false 안덮인것
	bool iscover = true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j] == false) {
				iscover = false;
			}
		}
	}
	if (iscover) {
		return 1;
	}
	int ret = 0;
	bool start = true;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			if (start) {
				for (int type = 0; type < 4; type++) {
					bool ok = true;
					int ny, nx;
					for (int type2 = 0; type2 < 3; type2++) {
						ny = y + coverType[type][type2][0];
						nx = x + coverType[type][type2][1];
						if (ny < 0 || ny >= H || nx < 0 || nx >= W) {
							ok = false;
						}
						if (board[ny][nx] == true) {
							ok = false;
						}
					}
					if (ok) {
						for (int type2 = 0; type2 < 3; type2++) {
							ny = y + coverType[type][type2][0];
							nx = x + coverType[type][type2][1];
							board[ny][nx] = true;
						}
						ret += boardcover(board);
						start = false;
						for (int type2 = 0; type2 < 3; type2++) {
							ny = y + coverType[type][type2][0];
							nx = x + coverType[type][type2][1];
							board[ny][nx] = false;
						}
					}
				}
			}
		}
	}
	return ret;
}
int main() {
	cin >> C;
	for (int i = 1; i <= C; i++) {
		cin >> H >> W;
		bool B[20][20];
		for (int i2 = 0; i2 < H; i2++) {
			for (int i3 = 0; i3 < W; i3++) {
				char t;
				cin >> t;
				if (t == '#') {
					B[i2][i3] = true;
				}
				else if (t == '.') {
					B[i2][i3] = false;
				}
			}
		}
		cout << boardcover(B) << endl;
	}
}