//result:맞았습니다!!
#include <iostream>
#include <cstring>
using namespace std;
int board[1001][1001];
int arr[101];
void putStar(int x, int y, int cnt) {
	if (cnt == 1) {
		board[y][x] = 1;
		return;
	}
	for (int i = 0; i < arr[cnt]; i++) {
		board[y][x + i] = 1;
	}
	for (int i = 1; i <= arr[cnt]-2; i++) {
		board[y + i][x] = 1;
		board[y + i][x + arr[cnt]-1] = 1;
	}
	for (int i = 0; i < arr[cnt]; i++) {
		board[y+arr[cnt]-1][x + i] = 1;
	}
	putStar(x + 2, y + 2, cnt - 1);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	arr[1] = 1;
	for (int i = 2; i <= 100; i++) {
		arr[i] = arr[i - 1] + 4;
	}
	putStar(1, 1, N);
	for (int i = 1; i <= arr[N]; i++) {
		for (int j = 1; j <= arr[N]; j++) {
			if (board[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << '\n';
	}
}