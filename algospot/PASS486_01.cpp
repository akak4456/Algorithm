//result:정답
#include <iostream>
#include <cmath>
using namespace std;
const int MAX_N = 10000000;
int minFactor[MAX_N + 1];
int co[MAX_N + 1];
void eratosthenes() {
	for (int i = 2; i <= MAX_N; i++)
		minFactor[i] = i;
	minFactor[0] = minFactor[1] = -1;
	int sqrtn = int(sqrt(MAX_N));
	for (int i = 2; i <= sqrtn; i++) {
		if (minFactor[i] == i) {
			for (int j = i * i; j <= MAX_N; j += i) {
				if (minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
	co[0] = co[1] = 1;
	for (int t = 2; t <= MAX_N; t++) {
		int p = t;
		int prev = minFactor[p];
		int tmpSum = 2;
		int tmpProduct = 1;
		while (p > 1) {
			p /= minFactor[p];
			if (p <= 1) {
				tmpProduct *= tmpSum;
				break;
			}
			if (prev == minFactor[p]) {
				tmpSum++;
			}
			else {
				tmpProduct *= tmpSum;
				prev = minFactor[p];
				tmpSum = 2;
			}
		}
		co[t] = tmpProduct;
	}
}
int c;
int n, lo, hi;
int main() {
	eratosthenes();
	std::ios::sync_with_stdio(false);
	cin >> c;
	while (c--) {
		cin >> n >> lo >> hi;
		int t = 0;
		for (int i = lo; i <= hi; i++) {
			if (n == co[i])
				t++;
		}
		cout << t << endl;
	}
}