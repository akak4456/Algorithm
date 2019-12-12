//result:맞았습니다!!
#include <iostream>
using namespace std;
int board[501][501];
int arr[101];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	arr[1] = 1;
	for (int i = 2; i <= 100; i++) {
		arr[i] = arr[i - 1] + 4;
	}
	int N;
	cin >> N;
	if (N == 1) {
		cout << "*\n";
	}
	else {
		for (int i = 3; i <= arr[N]; i++) {
			board[2][i] = -1;
		}
		int direction = 2;
		int upperBound = 3, lowerBound = arr[N] + 2;
		int leftBound = 1, rightBound = arr[N];
		int curX = arr[N], curY = 1;
		while (true) {
			bool isUpdated = false;
			if (direction == 1) {
				while (curY >= upperBound) {
					board[curY][curX] = 1;
					curY--;
					isUpdated = true;
				}
				curY++;
				upperBound += 2;
				direction = 2;
			}
			else if (direction == 2) {
				while (curX >= leftBound) {
					board[curY][curX] = 1;
					curX--;
					isUpdated = true;
				}
				curX++;
				leftBound += 2;
				direction = 3;
			}
			else if (direction == 3) {
				while (curY <= lowerBound) {
					board[curY][curX] = 1;
					curY++;
					isUpdated = true;
				}
				curY--;
				direction = 4;
				lowerBound -= 2;
			}
			else if (direction == 4) {
				while (curX <= rightBound) {
					board[curY][curX] = 1;
					curX++;
					isUpdated = true;
				}
				curX--;
				direction = 1;
				rightBound -= 2;
			}
			if (!isUpdated)
				break;
		}
		for (int i = 1; i <= arr[N] + 2; i++) {
			for (int j = 1; j <= arr[N]; j++) {
				if (board[i][j] == 1) {
					cout << "*";
				}
				else if(board[i][j] == 0){
					cout << " ";
				}
			}
			cout << "\n";
		}
	}
}