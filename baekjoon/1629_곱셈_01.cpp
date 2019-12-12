//result:틀렸습니다
#include <iostream>
using namespace std;
int A, B, C;
int bin[32];
int m[32];
void dectobin(int dec) {
	int idx = 0;
	int d = dec;
	while (d / 2 > 0) {
		bin[idx++] = d % 2;
		d /= 2;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> A >> B >> C;
	for (int i = 0; i < 32; i++)
		bin[i] = -1;
	dectobin(B);
	m[0] = A % C;
	for (int i = 1; i < 32; i++) {
		m[i] = (m[i - 1] % C * m[i - 1] % C) % C;
	}
	int ret = 1;
	for (int i = 0; i < 32; i++) {
		if (bin[i] == 1) {
			ret = (ret % C * m[i] % C) % C;
		}
	}
	cout << ret << '\n';
}
