//result:맞았습니다!!
#include <iostream>
using namespace std;
long long int A, B, C;
long long int bin[32];
long long int m[32];
void dectobin(long long int dec) {
	int idx = 0;
	long long int d = dec;
	bin[idx++] = d % 2;
	while (d / 2 > 0) {
		d /= 2;
		bin[idx++] = d % 2;
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
		m[i] = (m[i - 1]  * m[i - 1] ) % C;
	}
	long long int ret = 1;
	for (int i = 0; i < 32; i++) {
		//cout << bin[i] << endl;
		if (bin[i] == 1) {
			ret *= m[i];
			ret %= C;
		}
	}
	cout << ret%C << '\n';
}