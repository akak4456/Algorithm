//result:틀렸습니다
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		int cnt = 0;
		int diff = y - x;
		while (diff > 0) {
			int sq = sqrt(diff);
			cnt += 2 * sq - 1;
			diff -= sq * sq;
		}
		cout << cnt << endl;
	}
}