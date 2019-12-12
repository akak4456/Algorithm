//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> factor;
	factor.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> factor[i];
	}
	sort(factor.begin(), factor.end());
	if (N % 2 == 0) {
		cout << factor[N / 2 - 1] * factor[N / 2] << '\n';
	}
	else {
		cout << factor[N / 2] * factor[N / 2] << '\n';
	}
}