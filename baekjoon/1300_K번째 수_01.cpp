//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	int low = 1;
	int high = K;
	int result = -1;
	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N);
		}
		if (cnt < K)
			low = mid + 1;
		else {
			result = mid;
			high = mid - 1;
		}
	}
	cout << result << '\n';
}