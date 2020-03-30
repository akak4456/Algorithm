//result:시간 초과
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string A, B;
	cin >> A >> B;
	int sum[10001];
	memset(sum, 0, sizeof(sum));
	while (A.size() != B.size()) {
		A = "0" + A;
	}
	while (A.size() != B.size()) {
		B = "0" + B;
	}
	int n = A.size();
	for (int i = 0; i < n; i++) {
		sum[i] += (A[n - i - 1] - '0') + (B[n - i - 1] - '0');
		if (sum[i] >= 10) {
			sum[i + 1]++;
			sum[i] -= 10;
		}
	}
	string ans = "";
	int lastIdx = 10000;
	while (lastIdx > 0 &&sum[lastIdx] == 0)
		lastIdx--;
	for (int i = 0; i <= lastIdx; i++) {
		ans = to_string(sum[i]) + ans;
	}
	cout << ans << '\n';
}