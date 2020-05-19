//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
const int MOD = 45678;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int ans = 5;
	int added = 3;
	for (int i = 2; i <= N; i++) {
		ans += added;
		ans %= MOD;
		ans += added - 1;
		ans %= MOD;
		ans += added - 1;
		ans %= MOD;
		added++;
	}
	cout << ans << '\n';
}