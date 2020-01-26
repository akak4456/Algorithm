//result:정답
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N;
int tri[100][100];
int cache[100][100];
int maxCalc(int y, int x) {
	if (x > y) {
		return -INF;
	}
	int& ret = cache[y][x];
	if (y == N - 1) {
		return ret = tri[y][x];
	}
	if (ret != -1)
		return ret;
	ret = -INF;
	ret = max(ret, tri[y][x] + maxCalc(y + 1, x));
	ret = max(ret, tri[y][x] + maxCalc(y + 1, x + 1));
	return ret;
}
int cnt;
void cntCalc(int y, int x) {
	if (y == N-1) {
		cnt++;
		return;
	}
	if (tri[y][x] + cache[y + 1][x] == cache[y][x]) {
		cntCalc(y + 1, x);
	}
	if (tri[y][x] + cache[y + 1][x+1] == cache[y][x]) {
		cntCalc(y + 1, x+1);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	while (C--) {
		cnt = 0;
		memset(cache, -1, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> tri[i][j];
			}
		}
		//cout << maxCalc(0, 0) << '\n';
		maxCalc(0, 0);
		cntCalc(0, 0);
		cout << cnt << '\n';
	}
}