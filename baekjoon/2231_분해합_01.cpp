//result:맞았습니다!!
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	bool isCan = false;
	for (int i = 1; i <= N; i++) {
		int sum = i;
		int tmp = i;
		while (tmp > 0) {
			sum += tmp%10;
			tmp /= 10;
		}
		if (sum == N) {
			cout << i;
			isCan = true;
			break;
		}
	}
	if (!isCan)
		cout << 0;
}