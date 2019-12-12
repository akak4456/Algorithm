//result:시간초과
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int T, H, W, R, C;
bool board[10][10];
vector<string> block;
vector<vector<pair<int, int> > > rotations;
int blockSize;
vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[0].size(); j++) {
			ret[j][arr.size() - 1 - i] = arr[i][j];
		}
	}
	return ret;
}
void makeConvert() {
	rotations.clear();
	rotations.resize(4);
	for (int rot = 0; rot < 4; rot++) {
		int originY = -1, originX = -1;
		for (int i = 0; i < block.size(); i++) {
			for (int j = 0; j < block[i].size(); j++) {
				if (block[i][j] == '#') {
					if (originY == -1) {
						originY = i;
						originX = j;
					}
					rotations[rot].push_back(make_pair(i - originY, j - originX));
				}
			}
		}
		block = rotate(block);
	}
	sort(rotations.begin(), rotations.end());
	//rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	blockSize = rotations[0].size();
}
bool canPut(int y, int x, int type) {
	for (int i = 0; i < rotations[type].size(); i++) {
		int ny = y + rotations[type][i].first;
		int nx = x + rotations[type][i].second;
		if (ny < 0 || ny >= H || nx < 0 || nx >= W || board[ny][nx]) {
			return false;
		}
	}
	return true;
}
void putBlock(int y, int x, int type) {
	for (int i = 0; i < rotations[type].size(); i++) {
		int ny = y + rotations[type][i].first;
		int nx = x + rotations[type][i].second;
		board[ny][nx] = true;
	}
}
void popBlock(int y, int x, int type) {
	for (int i = 0; i < rotations[type].size(); i++) {
		int ny = y + rotations[type][i].first;
		int nx = x + rotations[type][i].second;
		board[ny][nx] = false;
	}
}
int best;
bool blockPrune(int placed) {
	int cnt = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j <W; j++)
			cnt += !(board[i][j]) ? 1 : 0;
	return ((cnt / blockSize) + placed <= best);
}
void boardCover(int placed) {
	if (blockPrune(placed)) {
		return;
	}
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
	if (y == -1) {
		best = max(best, placed);
		return;
	}
	for (int i = 0; i < rotations.size(); i++) {
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
		block.clear();
		rotations.clear();
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
		for (int y = 0; y < R; y++) {
			string tmp;
			cin >> tmp;
			block.push_back(tmp);
		}
		makeConvert();
		boardCover(0);
		cout << best << endl;
	}
}