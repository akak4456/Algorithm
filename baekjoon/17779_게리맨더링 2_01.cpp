//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
int A[21][21];
int dividend[21][21];
bool divide(int r, int c, int d1, int d2) {
	if (!(r >= 1))
		return false;
	if (!(r + d1 + d2 <= N))
		return false;
	if (!(c - d1 >= 1))
		return false;
	if (!(c + d2 <= N))
		return false;
	memset(dividend, 0, sizeof(dividend));
	for (int i = 0; i <= d1; i++) {
		dividend[r + i][c - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		dividend[r + i][c + i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		dividend[r + d1 + i][c - d1 + i] = 5;
	}
	for (int i = 0; i <= d1; i++) {
		dividend[r + d2 + i][c + d2 - i] = 5;
	}
	for (int i = 1; i < r+d1; i++) {
		for (int j = 1; j <= c; j++) {
			if (dividend[i][j] == 5)
				break;
			dividend[i][j] = 1;
		}
	}
	for (int i = 1; i <= r+d2; i++) {
		for (int j = N; j > c; j--) {
			if (dividend[i][j] == 5)
				break;
			dividend[i][j] = 2;
		}
	}
	for (int i = r+d1; i <= N; i++) {
		for (int j = 1; j < c-d1+d2; j++) {
			if (dividend[i][j] == 5)
				break;
			dividend[i][j] = 3;
		}
	}
	for (int i = r+d2 + 1; i <= N; i++) {
		for (int j = N; j >= c-d1+d2; j--) {
			if (dividend[i][j] == 5)
				break;
			dividend[i][j] = 4;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dividend[i][j] == 0) {
				dividend[i][j] = 5;
			}
		}

	}
	return true;
}
int cnt[6];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	int minDiff = 987654321;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (divide(r, c, d1, d2)) {
						memset(cnt, 0, sizeof(cnt));
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								cnt[dividend[i][j]] += A[i][j];
							}
						}
						int maxCnt = -1;
						int minCnt = 987654321;
						for (int i = 1; i <= 5; i++) {
							maxCnt = max(maxCnt, cnt[i]);
							minCnt = min(minCnt, cnt[i]);
						}
						minDiff = min(minDiff, maxCnt - minCnt);
					}
				}
			}
		}
	}
	cout << minDiff << '\n';
}