//result:맞았습니다!!
#include <iostream>
using namespace std;
int gcd(int a, int b) {
	int c;
	while (b) {
		if (a < b) {
			int temp = a;
			a = b;
			b = temp;
		}
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int ring[100];
	for (int i = 0; i < N; i++) {
		cin >> ring[i];
	}
	for (int i = 1; i < N; i++) {
		cout << (ring[0] / gcd(ring[0], ring[i])) << "/" << (ring[i] / gcd(ring[0], ring[i])) << '\n';
	}
}