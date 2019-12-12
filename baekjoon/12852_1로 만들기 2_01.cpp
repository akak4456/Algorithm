//result:틀렸습니다
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 1000000;
int DP[MAX_N + 1];
int N;
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
	int cnt = DP[N];
	for (int i = N; i >= 1; i--) {
		if (DP[i] == cnt) {
			cout << i << ' ';
			cnt--;
		}
	}
}