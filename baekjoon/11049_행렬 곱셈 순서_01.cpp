//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
int matrixSize[500][2];
int dp[500][500];
int N;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> matrixSize[i][0] >> matrixSize[i][1];
	for (int d = 1; d < N; d++) {
		for (int tx = 0; tx + d < N; tx++) {
			int ty = tx + d;
			dp[tx][ty] = 987654321;
			for (int mid = tx; mid < ty; mid++) {
				dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + matrixSize[tx][0] * matrixSize[mid][1] * matrixSize[ty][1]);
			}
		}
	}
	cout << dp[0][N - 1] << '\n';
}