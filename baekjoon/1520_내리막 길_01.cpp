//result:맞았습니다!!
#include <iostream>
using namespace std;
int M, N;
int Map[500][500];
int dp[500][500];
int solve(int x, int y) {
	int& ret = dp[x][y];
	if (ret != -1)
		return ret;
	if (y == M - 1 && x == N - 1)
		return 1;
	ret = 0;
	if (x - 1 >= 0 && Map[y][x] > Map[y][x-1])
		ret += solve(x - 1, y);
	if (x + 1 < N && Map[y][x] > Map[y][x + 1])
		ret += solve(x + 1, y);
	if (y - 1 >= 0 && Map[y][x] > Map[y - 1][x])
		ret += solve(x, y - 1);
	if (y + 1 < M && Map[y][x] > Map[y + 1][x])
		ret += solve(x, y + 1);
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; j++)
			dp[i][j] = -1;
	cin >> M >> N;
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin >> Map[i][j];
	cout << solve(0, 0) << '\n';
}