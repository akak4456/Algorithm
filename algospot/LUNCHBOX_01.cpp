//result:시간초과
#include <iostream>
using namespace std;
int C;
int n;
int m[10000];
int e[10000];
bool chosen[10000];
int solve(int minIdx) {
	int sum = 0;
	sum += m[minIdx];
	int remain = e[minIdx];
	chosen[minIdx] = true;
	while (true) {
		int minValue = 987654321;
		int minidx = -1;
		bool canBreak = true;
		for (int i = 0; i < n; i++) {
			if (chosen[i]) {
				continue;
			}
			canBreak = false;
			if (abs(remain - m[i]) < minValue) {
				minValue = abs(remain - m[i]);
				minidx = i;
			}
		}
		if (canBreak) {
			break;
		}
		chosen[minidx] = true;
		sum += m[minidx];
		if (m[minidx] <= remain) {
			remain = remain - m[minidx];
			if (remain < e[minidx]) {
				remain = e[minidx];
			}
		}
		else {
			remain = e[minidx];
		}
	}
	return sum;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> n;
		int minValue = 987654321;
		int minIdx = -1;
		for (int i = 0; i < n; i++) {
			cin >> m[i];
			if (m[i] < minValue) {
				minValue = m[i];
				minIdx = i;
			}
		}
		for (int i = 0; i < n; i++) {
			cin >> e[i];
			chosen[i] = false;
		}
		cout << solve(minIdx) << endl;
	}
}