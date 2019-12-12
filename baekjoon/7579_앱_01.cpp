//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int A[101];
int C[101];
int DP[101][10001];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j - C[i] < 0) {
				DP[i][j] = DP[i - 1][j];
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - C[i]] + A[i]);
			}
		}
	}
	for (int i = 0; i <= 10000; i++) {
		if (DP[N][i] >= M) {
			cout << i << '\n';
			break;
		}
	}
}