//result:맞았습니다!!
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 5000 + 1;
int board[MAX_N][MAX_N];
int arr[11];
void putStar(int x, int y, int cnt) {
	if (cnt == 1) {
		board[y][x] = 1;
	}
	else if (cnt % 2 == 0) {
		for (int i = 0; i < 2 * arr[cnt] - 1; i++) {
			board[y][i+x] = 1;
		}
		for (int i = 1; i < arr[cnt]; i++) {
			for (int j = 0; j <= i-1; j++) {
				board[y+i][x+j] = 0;
			}
			board[y+i][x+i] = 1;
			for (int j = i+1 ; j <= 2 * arr[cnt] - i - 3; j++) {
				board[y+i][x+j] = 0;
			}
			board[y+i][x+2 * arr[cnt] - i-2] = 1;
		}
		putStar(x-1+arr[cnt]/2+2, y-1+2, cnt - 1);
	}
	else if (cnt % 2 == 1) {
		for (int i = 0; i<arr[cnt] - 1; i++) {
			for (int j = 0; j < arr[cnt] - i - 1; j++) {
				board[y+i][x+j] = 0;
			}
			board[y+i][x+arr[cnt] - i - 1] = 1;
			if (i == 0)
				continue;
			for (int j = arr[cnt] - i; j < arr[cnt] + i - 1; j++) {
				board[y+i][x+j] = 0;
			}
			board[y+i][x+arr[cnt] + i-1] = 1;
		}
		for (int i = 1; i <= 2 * arr[cnt] - 1; i++) {
			board[y+arr[cnt] - 1][x+i-1] = 1;
		}
		putStar(x-1+arr[cnt]/2+2, y-1+arr[cnt]/2 + 1, cnt - 1);
	}
}
void printStar(int cnt) {
	for (int y = 1; y <= arr[cnt]; y++) {
		for (int x = 1; x <= MAX_N; x++) {
			if (board[y][x] == 1) {
				cout << "*";
			}
			else if(board[y][x] == 0){
				cout << " ";
			}
		}
		cout << "\n";
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(board, -1, sizeof(board));
	arr[1] = 1;
	for (int i = 2; i <= 10; i++) {
		arr[i] = arr[i - 1] * 2+1;
	}
	int N;
	cin >> N;
	putStar(1, 1, N);
	printStar(N);
}