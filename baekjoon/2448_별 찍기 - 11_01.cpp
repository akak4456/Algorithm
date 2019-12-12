//result:맞았습니다!!
#include <iostream>
using namespace std;
bool star[6150][6150];
void starFunc(int n, int x, int y) {
	if (n == 3) {
		star[y][x] = true;
		star[y][x+1] = true;
		star[y][x+2] = true;
		star[y][x+3] = true;
		star[y][x+4] = true;
		star[y-1][x+1] = true;
		star[y-1][x+3] = true;
		star[y-2][x+2] = true;
		return;
	}
	starFunc(n / 2, x + n / 2, y - n / 2);
	starFunc(n / 2, x, y);
	starFunc(n/2, x + n, y);
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	for (int y = 0; y < 6150; y++) {
		for (int x = 0; x < 6150; x++) {
			star[y][x] = 0;
		}
	}
	int N;
	cin >> N;
	starFunc(N, 0, N - 1);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N*2-1; x++) {
			if (star[y][x]) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << '\n';
	}
}