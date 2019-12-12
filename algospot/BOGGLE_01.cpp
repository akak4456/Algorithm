//result:시간초과
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int dx[8] = { 0,0,1,-1,-1,1,-1,1 };
const int dy[8] = { -1,1,0,0,-1,-1,1,1 };
int C;
char board[5][5];
int N;
vector<string> input;
bool isMatch(string src, int idx,int x,int y) {
	if (idx == src.size())
		return true;
	if (src[idx] == board[y][x]) {
		for (int i = 0; i < 8; i++) {
			if (x + dx[i] < 0 || x + dx[i] >= 5 || y + dy[i] < 0 || y + dy[i] >= 5) continue;
			if (isMatch(src, idx + 1, x + dx[i], y + dy[i]))
				return true;
		}
	}
	return false;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> board[i][j];
			}
		}
		cin >> N;
		input.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}
		for (int i = 0; i < N; i++) {
			bool isMatched = false;
			for (int x = 0; x < 5; x++) {
				for (int y = 0; y < 5; y++) {
					if (isMatch(input[i], 0, x, y)) {
						isMatched = true;
						break;
					}
				}
				if (isMatched)
					break;
			}
			if (isMatched) {
				cout << input[i] << " YES\n";
			}
			else {
				cout << input[i] << " NO\n";
			}
		}
	}
}