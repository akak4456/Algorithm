//result:시간초과
/*
2
4 7 2 3
##.##..
#......
#....##
#..####
###
#..
를 입력하면
(2,0)지역에 블록을 안넣고 그냥 지나친다.
*/
/*
블록 회전방식에 문제가 있었다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<pair<int, int> > ConvertType;
int T, H, W, R, C;
bool board[10][10];
bool block[10][10];
ConvertType convertTypes[4];
int len;
bool isSymmetry1() {
	for (int y = 0; y < R / 2; y++) {
		for (int x = 0; x < C; x++) {
			int reverseY = R - y - 1;
			if (block[y][x] != block[reverseY][x]) {
				return false;
			}
		}
	}
	return true;
}
bool isSymmetry2() {
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C / 2; x++) {
			int reverseX = C - x - 1;
			if (block[y][x] != block[y][reverseX]) {
				return false;
			}
		}
	}
	return true;
}
void makeConvert() {
	if (isSymmetry1() && isSymmetry2()) {
		len = 1;
		return;
	}
	len = 4;
	for (int idx = 1; idx < 4; idx++) {
		int preIdx = idx - 1;
		for (int i = 0; i < convertTypes[preIdx].size(); i++) {
			convertTypes[idx].push_back(make_pair(convertTypes[preIdx][i].second * -1, convertTypes[preIdx][i].first));
		}
	}
}
bool canPut(int y, int x, int type) {
	for (int i = 0; i < convertTypes[type].size(); i++) {
		int ny = y + convertTypes[type][i].second;
		int nx = x + convertTypes[type][i].first;
		if (ny < 0 || ny >= H || nx < 0 || nx >= W || board[ny][nx]) {
			return false;
		}
	}
	return true;
}
void putBlock(int y, int x, int type) {
	for (int i = 0; i < convertTypes[type].size(); i++) {
		int ny = y + convertTypes[type][i].second;
		int nx = x + convertTypes[type][i].first;
		board[ny][nx] = true;
	}
}
void popBlock(int y, int x, int type) {
	for (int i = 0; i < convertTypes[type].size(); i++) {
		int ny = y + convertTypes[type][i].second;
		int nx = x + convertTypes[type][i].first;
		board[ny][nx] = false;
	}
}
int best;
void boardCover(int placed) {
	int y = -1, x = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (!board[i][j]) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) break;
	}
	cout << placed << " " << y << " " <<x << endl;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (board[i][j]) {
				cout << "#";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
	if (y == -1) {
		best = max(best, placed);
		return;
	}
	for (int i = 0; i < len; i++) {
		if (canPut(y, x, i)) {
			putBlock(y, x, i);
			boardCover(placed + 1);
			popBlock(y, x, i);
		}
	}
	board[y][x] = true;
	boardCover(placed);
	board[y][x] = false;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		best = 0;
		cin >> H >> W >> R >> C;
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				char ch;
				cin >> ch;
				if (ch == '.') {
					board[y][x] = false;
				}
				else if (ch == '#') {
					board[y][x] = true;
				}
			}
		}
		int zeroX = -1;
		int zeroY = -1;
		for (int i = 0; i < 4; i++) {
			convertTypes[i].clear();
		}
		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				char ch;
				cin >> ch;
				if (ch == '.') {
					block[y][x] = false;
				}
				else if (ch == '#') {
					block[y][x] = true;
					if (zeroX == -1 && zeroY == -1) {
						zeroX = x;
						zeroY = y;
						convertTypes[0].push_back(make_pair(0, 0));
					}
					else {
						convertTypes[0].push_back(make_pair(x - zeroX, y - zeroY));
					}
				}
			}
		}
		makeConvert();
		boardCover(0);
		cout << best << endl;
	}
}