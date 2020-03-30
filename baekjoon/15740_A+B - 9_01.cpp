//result:100점
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
	int signA=1, signB=1;
	cin >> A >> B;
	if (A[0] == '-')
		signA = 0;
	if (B[0] == '-')
		signB = 0;
	if (signA == 0)
		A = A.substr(1);
	if (signB == 0)
		B = B.substr(1);
	while (A.size() < B.size()) {
		A = "0" + A;
	}
	while (B.size() < A.size()) {
		B = "0" + B;
	}
	if (signA == signB) {
		//덧셈 진행
		int n = A.size();
		int sum[10001];
		string ans;
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++) {
			sum[i] += (A[n - i - 1] - '0') + (B[n - i - 1] - '0');
			if (sum[i] >= 10) {
				sum[i + 1]++;
				sum[i] -= 10;
			}
		}

		int lastIdx = 10000;
		while (lastIdx > 0 && sum[lastIdx] == 0)
			lastIdx--;
		for (int i = 0; i <= lastIdx; i++) {
			ans = to_string(sum[i]) + ans;
		}
		if (signA == 0)
			ans = "-" + ans;
		cout << ans << '\n';
	}
	else {
		//뺄셈 진행
		int n = A.size();
		int diff[10001];
		string ans;
		memset(diff, 0, sizeof(diff));
		//큰수에서 작은수를 뺀다 큰수를 A
		//cout << A << ' ' << B << endl;
		string oldA = A, oldB = B;
		if (A < B) {
			string tmp = A;
			A = B;
			B = tmp;
		}
		for (int i = 0; i < n; i++) {
			diff[i] += (A[n - i - 1] - '0') - (B[n - i - 1] - '0');
			if (diff[i] < 0) {
				diff[i + 1]--;
				diff[i] += 10;
			}
		}
		int lastIdx = 10000;
		while (lastIdx > 0 && diff[lastIdx] == 0)
			lastIdx--;
		for (int i = 0; i <= lastIdx; i++) {
			ans = to_string(diff[i]) + ans;
		}
		//cout << ans << endl;
		if (signA == 0) {
			if (oldA > oldB) {
				ans = "-" + ans;
			}
		}
		else if(signB == 0) {
			if (oldA < oldB) {
				ans = "-" + ans;
			}
		}
		cout << ans << '\n';
	}
}