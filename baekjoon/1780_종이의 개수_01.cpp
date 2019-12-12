//result:맞았습니다!!
#include <iostream>
using namespace std;
int N;
int paper[2187][2187];
int cnt[3] = { 0,0,0 };
void solve(int startX, int endX, int startY, int endY) {
	//cout << startX << ' ' << endX << ' ' << startY << ' ' << endY << endl;
	int kind = paper[startY][startX];
	bool isCan = true;
	for (int y = startY; y <= endY; y++) {
		for (int x = startX; x <= endX; x++) {
			if (paper[y][x] != kind) {
				isCan = false;
				break;
			}
		}
	}
	
	if (isCan) {
		cnt[kind + 1]++;
		return;
	}
	else {
		int div = (endX - startX + 1) / 3;
		solve(startX, startX+div - 1, startY, startY+div - 1);
		solve(startX + div, startX + 2*div - 1, startY, startY+div - 1);
		solve(startX + 2*div, endX, startY, startY+div - 1);

		solve(startX, startX + div -1 , startY + div, startY + 2*div - 1);
		solve(startX + div, startX + 2 * div - 1, startY + div, startY + 2*div - 1);
		solve(startX + 2 * div, endX, startY + div , startY + 2*div - 1);

		solve(startX, startX + div - 1, startY + 2 * div, endY);
		solve(startX + div, startX + 2 * div - 1, startY + 2 * div, endY);
		solve(startX + 2 * div, endX, startY + 2 * div, endY);
	}
	
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> paper[y][x];
	solve(0, N - 1, 0, N - 1);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << endl;
}