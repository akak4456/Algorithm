//result:맞았습니다!!
#include <iostream>
using namespace std;
int N, M;
long long int H[1000000];
int solve() {
	long long int start = 0;
	long long int end = 2000000000;
	while (end - start > 1) {
		long long int middle = (start + end) / 2;
		long long int sum = 0;
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
	long long int sum = 0;
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