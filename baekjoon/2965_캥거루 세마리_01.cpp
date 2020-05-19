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
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A, B, C;
	cin >> A >> B >> C;
	int ans = -1;
	ans = max(ans, B - A - 1);
	ans = max(ans, C - B - 1);
	cout << ans << '\n';
}