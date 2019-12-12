//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C;
int N;
int H[20000];
int solve(int left, int right) {
	if (left == right) return H[left];
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	int height = min(H[lo], H[hi]);
	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || H[lo - 1] < H[hi + 1])) {
			hi++;
			height = min(height, H[hi]);
		}
		else {
			lo--;
			height = min(height, H[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> H[i];
		}
		cout << solve(0, N - 1) << '\n';
	}
}