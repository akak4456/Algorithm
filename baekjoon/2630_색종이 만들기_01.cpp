//result:맞았습니다!!
#include <iostream>
using namespace std;
int N;
int paper[128][128];
int whiteCnt = 0;
int blueCnt = 0;
void solve(int startX, int endX, int startY, int endY) {
	//cout << startX << ' ' << endX << ' ' << startY << ' ' << endY << endl;
	bool isWhite = (paper[startY][startX] == 0);
	bool isCan = true;
	for (int y = startY; y <= endY; y++) {
		for (int x = startX; x <= endX; x++) {
			if (isWhite && paper[y][x] == 1) {
				isCan = false;
				break;
			}
			if (!isWhite && paper[y][x] == 0) {
				isCan = false;
				break;
			}
		}
	}
	if (isCan) {
		if (isWhite)
			whiteCnt++;
		else
			blueCnt++;
		return;
	}
	else {
		solve(startX, (startX+endX) / 2, startY, (startY+endY) / 2);
		solve((startX + endX) /2+1, endX, startY, (startY + endY) / 2);
		solve(startX, (startX + endX) / 2, (startY + endY) /2+1, endY);
		solve((startX + endX) /2+1, endX, (startY + endY) /2+1, endY);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++)
			cin >> paper[y][x];
	}
	solve(0, N - 1, 0, N - 1);
	cout << whiteCnt << '\n';
	cout << blueCnt << '\n';
}