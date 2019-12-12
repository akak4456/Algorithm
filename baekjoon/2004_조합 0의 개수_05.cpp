//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	long long int n, r;
	cin >> n >> r;
	int cnt1_1 = 0,cnt1_2=0,cnt1=0, cnt2_1 = 0, cnt2_2 = 0, cnt2 = 0;
	long long int t = 5;
	while (n / t > 0) {
		cnt1_1 += n / t;
		t *= 5;
	}
	t = 2;
	while (n / t > 0) {
		cnt1_2 += n / t;
		t *= 2;
	}
	t = 5;
	while (r / t > 0) {
		cnt2_1 += r / t;
		t *= 5;
	}
	t = 2;
	while (r / t > 0) {
		cnt2_2 += r / t;
		t *= 2;
	}
	t = 5;
	while ((n-r) / t > 0) {
		cnt2_1 += (n - r) / t;
		t *= 5;
	}
	t = 2;
	while ((n - r) / t > 0) {
		cnt2_2 += (n - r) / t;
		t *= 2;
	}
	cout << min(cnt1_1 - cnt2_1,cnt1_2 - cnt2_2) << endl;
}