//result:정답
#include <iostream>
#include <algorithm>
using namespace std;
int C;
int N;
const int EMPTY = 987654321;
int board[51];
int cache[51][51];
int play(int left, int right) {
	if (left > right) return 0;
	int& ret = cache[left][right];
	if (ret != EMPTY) return ret;
	ret = max(board[left] - play(left + 1, right), board[right] - play(left, right - 1));
	if (right - left + 1 >= 2) {
		ret = max(ret, -play(left + 2, right));
		ret = max(ret, -play(left, right - 2));
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		for (int i = 1; i <= 50; i++) {
			for (int j = 1; j <= 50; j++) {
				cache[i][j] = EMPTY;
			}
		}
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> board[i];
		}
		cout << play(1, N) << endl;
	}
}