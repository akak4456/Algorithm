//result:맞았습니다!!
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int a=1, b=1, c;
	int N;
	cin >> N;
	if (N == 1)
		cout << 1 << '\n';
	else {
		int cnt = N - 1;
		while (cnt > 0) {
			cnt--;
			c = (a%15746 + b%15746)%15746;
			b = a%15746;
			a = c%15746;
		}
		cout << c << '\n';
	}
}