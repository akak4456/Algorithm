//result:틀렸습니다
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	long long int n, r;
	cin >> n >> r;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int t = 5;
	while (n / t > 0) {
		cnt1 += n / t;
		t *= 5;
	}
	t = 5;
	while (r / t > 0) {
		cnt2 += r / t;
		t *= 5;
	}
	t = 5;
	while ((n-r) / t > 0) {
		cnt3 += (n-r) / t;
		t *= 5;
	}
	cout << cnt1 - cnt2 - cnt3 << endl;
}