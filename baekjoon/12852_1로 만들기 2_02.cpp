//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 1000000;
const int INF = 987654321;
int DP[MAX_N + 1];
int N;
void go(int n) {
	if (n <= 0)
		return;
	cout << n << ' ';
	int ans1 = INF, ans2 = INF, ans3 = DP[n - 1];
	if (n % 3 == 0) {
		ans1 = DP[n / 3];
	}
	if (n % 2 == 0) {
		ans2 = DP[n / 2];
	}
	if (ans1 < ans2)
		go(n / 3);
	else if (ans2 < ans3)
		go(n / 2);
	else
		go(n - 1);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//memset(DP, -1, sizeof(DP));
	cin >> N;
	DP[1] = 0;
	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0) {
			DP[i] = min(DP[i], DP[i / 2]+1);
		}
		if (i % 3 == 0) {
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
	}
	cout << DP[N] << '\n';
	go(N);
}