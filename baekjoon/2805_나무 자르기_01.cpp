//result:틀렸습니다
#include <iostream>
using namespace std;
int N, M;
int H[1000000];
int solve() {
	int start = 0;
	int end = 1000000000;
	while (end - start > 1) {
		int middle = (start + end) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (H[i] - middle > 0) {
				sum += H[i] - middle;
			}
		}
		if (sum < M) {
			end = middle-1;
		}
		else {
			start = middle;
		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (H[i] - end > 0) {
			sum += H[i] - end;
		}
	}
	if (sum >= M)
		return end;
	return start;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> H[i];
	cout << solve() << '\n';
}