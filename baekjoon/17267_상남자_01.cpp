//result:틀렸습니다
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N, M;
int L, R;
int board[1000][1000];
void dfs(int y, int x,int remainL,int remainR) {
	board[y][x] = 3;
	for (int ny = y; ny >= 0; ny--) {
		if (board[ny][x] == 1)
			break;
		if (board[ny][x] == 0) {
			dfs(ny, x, remainL, remainR);
		}
	}
	for (int ny = y; ny < N; ny++) {
		if (board[ny][x] == 1)
			break;
		if (board[ny][x] == 0) {
			dfs(ny, x, remainL, remainR);
		}
	}
	int cnt = 0;
	for (int nx = x; nx >= x - remainL; nx--) {
		if (nx < 0)
			break;
		if (board[y][nx] == 1)
			break;
		if (board[y][nx] == 0) {
			dfs(y, nx, remainL - cnt, remainR);
		}
		cnt++;
	}
	cnt = 0;
	for (int nx = x; nx <= x + remainR; nx++) {
		if (nx >= M)
			break;
		if (board[y][nx] == 1)
			break;
		if (board[y][nx] == 0) {
			dfs(y, nx, remainL, remainR-cnt);
		}
		cnt++;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	cin >> L >> R;
	int startPosX = -1, startPosY = -1;
	for (int i = 0; i < N; i++) {
		string src;
		cin >> src;
		for (int j = 0; j < M; j++) {
			board[i][j] = src[j] - '0';
			if (board[i][j] == 2) {
				startPosX = j;
				startPosY = i;
			}
		}
	}
	dfs(startPosY, startPosX,L,R);
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 3)
				cnt++;
		}
	}
	cout << cnt << '\n';
}