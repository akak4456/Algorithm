//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int matrix[301][301];
int cache[301][301];
int N, M;
int K;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cache[i][j] = matrix[i][j];
			cache[i][j] += cache[i - 1][j];
			cache[i][j] += cache[i][j - 1];
			cache[i][j] -= cache[i - 1][j - 1];
			//cout << i << ' ' << j << ' ' << cache[i][j] << '\n';
		}
	}
	cin >> K;
	while (K--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << cache[x][y] - cache[i - 1][y] - cache[x][j - 1] + cache[i - 1][j - 1] << '\n';
	}
}