//result:맞았습니다!!
#include <iostream>
using namespace std;
const int MAX_N = 100000 + 1;
int N, M;
int arr[MAX_N];
int dp[MAX_N];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}
	for (int i = 0; i < M; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		cout << dp[t2] - dp[t1-1] << '\n';
	}
}