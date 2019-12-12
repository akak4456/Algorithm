//result:맞았습니다!!
#include <iostream>
using namespace std;
int N;
int paper[64][64];
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
			cout << '0';
		else
			cout << '1';
		return;
	}
	else {
		cout << '(';
		solve(startX, (startX+endX) / 2, startY, (startY+endY) / 2);
		solve((startX + endX) /2+1, endX, startY, (startY + endY) / 2);
		solve(startX, (startX + endX) / 2, (startY + endY) /2+1, endY);
		solve((startX + endX) /2+1, endX, (startY + endY) /2+1, endY);
		cout << ')';
	}
	
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			paper[i][j] = str[j] - '0';
		}
	}
	solve(0, N - 1, 0, N - 1);
}