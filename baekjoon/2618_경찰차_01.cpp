//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 987654321;
int dp[1001][1001], n, w, back[1001];
pair<int, int> d[1001];
int getdist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int func(int x, int y) {
	if (x == w || y == w) return 0;
	int& ret = dp[x][y];
	if (ret != -1)return ret;
	int fir, sec;
	if (!x)
		fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], { 1,1 });
	else
		fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], d[x]);
	if (!y)
		sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], { n,n });
	else
		sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], d[y]);
	if (fir < sec) {
		return ret = fir;
	}
	else {
		return ret = sec;
	}
}
void solve(int x, int y) {
	if (x == w || y == w) return;
	int fir, sec;
	if (!x)
		fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], { 1,1 });
	else
		fir = func(max(x, y) + 1, y) + getdist(d[max(x, y) + 1], d[x]);
	if (!y)
		sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], { n,n });
	else
		sec = func(x, max(x, y) + 1) + getdist(d[max(x, y) + 1], d[y]);
	if (fir < sec) {
		back[max(x, y) + 1] = 1;
		solve(max(x, y) + 1, y);
	}
	else {
		back[max(x, y) + 1] = 2;
		solve(x, max(x, y) + 1);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			dp[i][j] = -1;
	cin >> n >> w;
	for (int i = 1; i <= w; i++)
		cin >> d[i].first >> d[i].second;
	cout << func(0, 0) << '\n';
	solve(0, 0);
	for (int i = 1; i <= w; i++) {
		cout << back[i] << '\n';
	}
}