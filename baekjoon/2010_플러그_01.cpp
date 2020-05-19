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
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		ans += t;
		ans--;
	}
	cout << ans << '\n';
}