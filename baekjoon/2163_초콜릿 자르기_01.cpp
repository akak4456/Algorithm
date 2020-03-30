//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N,M;
int cache[301][301];
int solve(int H, int W) {
	if (H == 1 && W == 1)
		return 0;
	int& ret = cache[H][W];
	if (ret != -1) return ret;
	ret = 987654321;
	for (int i = 1; i <= H; i++) {
		ret = min(ret, solve(i, W) + solve(H - i, W) + 1);
	}
	for (int i = 1; i <= W; i++) {
		ret = min(ret, solve(H, i) + solve(H, W - i) + 1);
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	memset(cache, -1, sizeof(cache));
	cout << solve(N, M) << '\n';
}