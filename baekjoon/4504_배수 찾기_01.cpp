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
	int N;
	cin >> N;
	int t;
	while (cin >> t) {
		if (t == 0)
			break;
		string ans = "";
		if (t % N == 0) {
			ans = " is a multiple of ";
		}
		else {
			ans = " is NOT a multiple of ";
		}
		cout << t << ans << N << ".\n";
	}
}