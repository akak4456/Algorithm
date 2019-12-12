//result:시간 초과
#include <iostream>
#include <algorithm>
using namespace std;
int num[100];
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	if (N % 2 == 0) {
		int sum = num[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			sum -= num[i];
		}
		for (int M = 2; M <= sum; M++) {
			if (sum % M == 0) {
				cout << M << ' ';
			}
		}
	}
	else {
		int sum = num[N - 1];
		for (int i = N - 2; i >= 1; i--) {
			sum -= num[i];
		}
		sum += num[0];
		for (int M = 2; M <= (sum > num[0] ? sum : num[0]); M++) {
			if (sum % M == num[0] % M)
				cout << M << ' ';
		}
	}
}