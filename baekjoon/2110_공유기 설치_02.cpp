//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
long long int x[200000];
long long int solve() {
	long long int left = 1;
	long long int right = x[N - 1] - x[0];
	long long int d = 0;
	long long int ans = 0;
	while (left <= right) {
		long long int mid = (left + right) / 2;
		long long int start = x[0];
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			d = x[i] - start;
			if (mid <= d) {
				cnt++;
				start = x[i];
			}
		}
		if (cnt >= C) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	sort(x, x + N);
	cout << solve() << '\n';
}