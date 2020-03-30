//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int board[20][20];
int N;
void up() {
	for (int col = 0; col < N; col++) {
		vector<int> newLine;
		for (int row = 0; row < N; row++) {
			if (board[row][col] != 0) {
				newLine.push_back(board[row][col]);
			}
		}
		for (int row = 0; row < newLine.size(); row++) {
			board[row][col] = newLine[row];
		}
		for (int row = newLine.size(); row < N; row++) {
			board[row][col] = 0;
		}
	}
	for (int col = 0; col < N; col++) {
		for (int row = 0; row < N - 1; row++) {
			if (board[row][col] != 0) {
				if (board[row][col] == board[row + 1][col]) {
					board[row][col] *= 2;
					board[row + 1][col] = 0;
				}
			}
		}
	}
		for (int col = 0; col < N; col++) {
			vector<int> newLine;
			for (int row = 0; row < N; row++) {
				if (board[row][col] != 0) {
					newLine.push_back(board[row][col]);
				}
			}
			for (int row = 0; row < newLine.size(); row++) {
				board[row][col] = newLine[row];
			}
			for (int row = newLine.size(); row < N; row++) {
				board[row][col] = 0;
			}
		}
}
void down() {
	for (int col = 0; col < N; col++) {
		vector<int> newLine;
		for (int row = 0; row < N; row++) {
			if (board[row][col] != 0) {
				newLine.push_back(board[row][col]);
			}
		}
		for (int row = 0; row < N - newLine.size(); row++) {
			board[row][col] = 0;
		}
		for (int row = N - newLine.size(); row < N; row++) {
			board[row][col] = newLine[row - (N - newLine.size())];
		}
	}
	for (int col = 0; col < N; col++) {
		for (int row = N-1; row > 0; row--) {
			if (board[row][col] != 0) {
				if (board[row][col] == board[row - 1][col]) {
					board[row][col] *= 2;
					board[row - 1][col] = 0;
				}
			}
		}
	}
		for (int col = 0; col < N; col++) {
			vector<int> newLine;
			for (int row = 0; row < N; row++) {
				if (board[row][col] != 0) {
					newLine.push_back(board[row][col]);
				}
			}
			for (int row = 0; row < N-newLine.size(); row++) {
				board[row][col] = 0;
			}
			for (int row = N - newLine.size(); row < N; row++) {
				board[row][col] = newLine[row-(N - newLine.size())];
			}
		}
}
void left() {
	for (int row = 0; row < N; row++) {
		vector<int> newLine;
		for (int col = 0; col < N; col++) {
			if (board[row][col] != 0)
				newLine.push_back(board[row][col]);
		}
		for (int col = 0; col < newLine.size(); col++) {
			board[row][col] = newLine[col];
		}
		for (int col = newLine.size(); col < N; col++) {
			board[row][col] = 0;
		}
	}
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N - 1; col++) {
			if (board[row][col] != 0) {
				if (board[row][col] == board[row][col+1]) {
					board[row][col] *= 2;
					board[row][col+1] = 0;
				}
			}
		}
	}
		for (int row = 0; row < N; row++) {
			vector<int> newLine;
			for (int col = 0; col < N; col++) {
				if (board[row][col] != 0)
					newLine.push_back(board[row][col]);
			}
			for (int col = 0; col < newLine.size(); col++) {
				board[row][col] = newLine[col];
			}
			for (int col = newLine.size(); col < N; col++) {
				board[row][col] = 0;
			}
		}
}
void right() {
	for (int row = 0; row < N; row++) {
		vector<int> newLine;
		for (int col = 0; col < N; col++) {
			if (board[row][col] != 0)
				newLine.push_back(board[row][col]);
		}
		for (int col = 0; col < N - newLine.size(); col++) {
			board[row][col] = 0;
		}
		for (int col = N - newLine.size(); col < N; col++) {
			board[row][col] = newLine[col - (N - newLine.size())];
		}
	}
	for (int row = 0; row < N; row++) {
		for (int col = N-1; col > 0; col--) {
			if (board[row][col] != 0) {
				if (board[row][col] == board[row][col - 1]) {
					board[row][col] *= 2;
					board[row][col - 1] = 0;
				}
			}
		}
	}
		for (int row = 0; row < N; row++) {
			vector<int> newLine;
			for (int col = 0; col < N; col++) {
				if (board[row][col] != 0)
					newLine.push_back(board[row][col]);
			}
			for (int col = 0; col < N-newLine.size(); col++) {
				board[row][col] = 0;
			}
			for (int col = N - newLine.size(); col < N; col++) {
				board[row][col] = newLine[col-(N-newLine.size())];
			}
		}
}
void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}
int best;
void solve(int cnt) {
	if (cnt > 5)
		return;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			best = max(best, board[i][j]);
		}
	}
	int oldBoard[20][20];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			oldBoard[i][j] = board[i][j];
		}
	}

	up();
	solve(cnt + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = oldBoard[i][j];
		}
	}

	down();
	solve(cnt + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = oldBoard[i][j];
		}
	}

	left();
	solve(cnt + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = oldBoard[i][j];
		}
	}

	right();
	solve(cnt + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = oldBoard[i][j];
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	//up();
	//print();
	solve(0);
	cout << best << '\n';
}