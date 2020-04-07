//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int burger[3];
	int beverage[2];
	cin >> burger[0] >> burger[1] >> burger[2];
	cin >> beverage[0] >> beverage[1];
	int ans = 987654321;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			ans = min(ans, burger[i] + beverage[j] - 50);
		}
	}
	cout << ans << '\n';
}