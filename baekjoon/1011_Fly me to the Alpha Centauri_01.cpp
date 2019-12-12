//result:시간 초과
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		int cnt = 0;
		int n = 1;
		int diff = y - x;
		while (diff > 0) {
			while (n * n < diff) {
				n++;
			}
			if (diff % (n * n) != 0) {
				n--;
			}
			cnt += 2 * n - 1;
			diff -= n * n;
		}
		cout << cnt << '\n';
	}
}