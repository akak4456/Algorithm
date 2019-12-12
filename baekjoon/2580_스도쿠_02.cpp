//result:틀렸습니다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool finish = false;
void sudoku(int su[9][9]) {
	bool isCan = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (finish)
				return;
			if (su[i][j] == 0) {
				isCan = false;
				vector<int> possible;
				for (int t1 = 1; t1 <= 9; t1++) {
					bool canPush = true;
					for (int t2 = 0; t2 < 9; t2++) {
						if (su[i][t2] == t1 || su[t2][j] == t1) {
							canPush = false;
							break;
						}
					}
					int startY = (i / 3) * 3, startX = (j / 3) * 3;
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
				if (possible.size() == 1) {
					int tmp = su[i][j];
					su[i][j] = possible[0];
					sudoku(su);
					su[i][j] = tmp;
				}
			}
		}
	}
	if (isCan) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << su[i][j] << ' ';
			cout << '\n';
		}
		finish = true;
		return;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	int su[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> su[i][j];
	sudoku(su);
}