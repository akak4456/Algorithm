//result:틀렸습니다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool finish = false;
int su[9][9];
void sudoku(int cnt) {
	if (cnt == 81) {
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				cout << su[y][x] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	int y = cnt / 9;
	int x = cnt % 9;
	if (su[y][x])
		sudoku(cnt + 1);
	else {
		vector<int> possible;
		for (int t1 = 1; t1 <= 9; t1++) {
			bool canPush = true;
			for (int t2 = 0; t2 < 9; t2++) {
				if (su[y][t2] == t1 || su[t2][x] == t1) {
					canPush = false;
					break;
				}
			}
			int startY = (y / 3) * 3, startX = (x / 3) * 3;
			for (int ny = startY; ny < startY + 3; ny++) {
				if (!canPush)
					break;
				for (int nx = startX; nx < startX + 3; nx++) {
					if (su[ny][nx] == t1) {
						canPush = false;
						break;
					}
				}
			}
			if (canPush) {
				possible.push_back(t1);
			}
		}
		for (int i = 0; i < possible.size(); i++) {
			int tmp = su[y][x];
			su[y][x] = possible[i];
			sudoku(cnt + 1);
			su[y][x] = tmp;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> su[i][j];
	sudoku(0);
}