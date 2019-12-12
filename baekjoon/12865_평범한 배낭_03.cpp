//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int dp[100001][101];
vector<pair<int, int> > arr;
int solve(int w,int pos) {
	if (w < 0) {
		return -987654321;
	}
	if (w == 0 || pos == N)
		return 0;
	int& ret = dp[w][pos];
	if (ret != -1)
		return ret;
	ret = 0;
	ret = max(solve(w - arr[pos].first, pos + 1) + arr[pos].second, solve(w, pos + 1));
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < 100001; i++)
		for(int j=0;j<101;j++)
		dp[i][j] = -1;
	for (int i = 0; i < N; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		arr.push_back(make_pair(t1, t2));
	}
	cout << solve(K,0) << '\n';
}