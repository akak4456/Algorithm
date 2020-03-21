//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, x, y, K;
int board[20][20];
int dice[6+1];
bool move(int query) {
	int old1 = dice[1];
	int old2 = dice[2];
	int old3 = dice[3];
	int old4 = dice[4];
	int old5 = dice[5];
	int old6 = dice[6];
	if (query == 1) {
		//동쪽 이동
		if (y + 1 >= M)
			return false;
		y++;
		dice[1] = old4;
		dice[3] = old1;
		dice[6] = old3;
		dice[4] = old6;
	}
	else if (query == 2) {
		//서쪽 이동
		if (y - 1 < 0)
			return false;
		y--;
		dice[4] = old1;
		dice[6] = old4;
		dice[3] = old6;
		dice[1] = old3;
	}
	else if (query == 3) {
		//북쪽 이동
		if (x - 1 < 0)
			return false;
		x--;
		dice[6] = old2;
		dice[5] = old6;
		dice[1] = old5;
		dice[2] = old1;
	}
	else if (query == 4) {
		//남쪽 이동
		if (x + 1 >= N)
			return false;
		x++;
		dice[5] = old1;
		dice[6] = old5;
		dice[2] = old6;
		dice[1] = old2;
	}
	return true;
}
void write() {
	if (board[x][y] == 0) {
		board[x][y] = dice[6];
	}
	else {
		dice[6] = board[x][y];
		board[x][y] = 0;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	while (K--) {
		int query;
		cin >> query;
		if (move(query)) {
			write();
			cout << dice[1] << '\n';
		}
		
	}
}