//result:맞았습니다!!
/*
2-a 조건을 잘못 이해해서 헤맸음
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
//북 서 남 동
int n, m;
int r, c, d;
int board[50][50];
void printBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << board[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}
void dfs(int y, int x, int d) {
	board[y][x] = 2;
	//printBoard();
	for (int i = 0; i < 4; i++) {
		d = (d + 1) % 4;
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny >= 0 && ny < n && nx >= 0 && nx < m && board[ny][nx] == 0) {
			dfs(ny, nx, d);
			return;
		}
	}
	if (board[y + dy[(d + 2) % 4]][x + dx[(d + 2) % 4]] != 1) {
		dfs(y + dy[(d + 2) % 4], x + dx[(d + 2) % 4], d);
	}

}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	if (d == 1)
		d = 3;
	else if (d == 3)
		d = 1;
	//cout << endl;
	dfs(r, c, d);
	//printBoard();
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 2)
				cnt++;
	cout << cnt << '\n';
}