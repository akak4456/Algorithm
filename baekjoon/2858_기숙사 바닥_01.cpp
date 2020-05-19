//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int R, B;
	cin >> R >> B;
	for (int i = 1; i <= B + R; i++) {
		if ((B + R) % i == 0) {
			int ans1 = i;
			int ans2 = (B + R) / i;
			if (ans1 < ans2) {
				int tmp = ans1;
				ans1 = ans2;
				ans2 = tmp;
			}
			//ans1이 더 큼
			if (2 * ans1 + 2 * ans2 == R + 4) {
				cout << ans1 << ' ' << ans2 << '\n';
				break;
			}
		}
	}
}