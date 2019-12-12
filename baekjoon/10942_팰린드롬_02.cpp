//result:맞았습니다!!
#include <iostream>
#include <cstring>
using namespace std;
int N, M;
int dp[2001][2001];//start ~ end 가 회문이 맞는지 맞으면 1 틀리면 0
int arr[2001];
int solve(int start, int end) {
	if (start == end) {
		return dp[start][end] = 1;
	}
	else if (end - start == 1) {
		if (arr[start] == arr[end])
			return dp[start][end] = 1;
		else
			return dp[start][end] = 0;
	}
	int& ret = dp[start][end];
	if (ret != -1)
		return ret;
	if (arr[start] != arr[end]) {
		return ret = 0;
	}
	else {
		return ret = solve(start + 1, end - 1);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	cin >> M;
	while (M--) {
		int s, e;
		cin >> s >> e;
		cout << solve(s, e) << '\n';
	}
}