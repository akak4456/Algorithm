//result:틀렸습니다
#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
long long int x[200000];
int solve() {
	int start = 0;
	int end = N;//x idx
	while (end-start > 1) {
		int middle = (start + end) / 2;
		long long int minDist = x[middle] - x[0];
		//cout << middle << ' ' << minDist << endl;
		int cnt = C - 2;
		bool isCan = false;
		int startIdx = middle;
		int endIdx = middle + 1;
		while (cnt > 0) {
			while (endIdx < N&&x[endIdx] - x[startIdx] < minDist) {
				endIdx++;
			}
			if (x[endIdx] - x[startIdx] < minDist) {
				isCan = false;
				break;
			}
			cnt--;
			if (cnt == 0) {
				isCan = true;
				break;
			}
			startIdx = endIdx;
			endIdx++;
		}
		if (!isCan) {
			end = middle - 1;
		}
		else {
			start = middle;
		}
	}
	int cnt = C - 2;
	bool isCan = false;
	long long int minDist = x[end] - x[0];
	int startIdx = end;
	int endIdx = end + 1;
	while (cnt > 0) {
		while (endIdx < N && x[endIdx] - x[startIdx] < minDist) {
			endIdx++;
		}
		cnt--;
		if (cnt == 0) {
			isCan = true;
			break;
		}
		startIdx = endIdx;
		endIdx++;
	}
	if (isCan)
		return end;
	return start;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	sort(x, x + N);
	int idx = solve();
	cout << x[idx]-x[0] << '\n';
}