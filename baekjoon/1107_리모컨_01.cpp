//result:틀렸습니다
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N, M;
int broken[10];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		broken[t] = 1;
	}
	if (N == 100) {
		cout << "0\n";
	}
	else {
		int ans = 987654321;
		for (int i = 0; i <= 999999; i++) {
			string s = to_string(i);
			bool canDo = true;
			for (int idx = 0; idx < s.size(); idx++) {
				int nxt = s[idx] - '0';
				if (broken[nxt] == 1) {
					canDo = false;
					break;
				}
			}
			if (canDo) {
				//cout << i << endl;
				int t = abs(N - i) + s.size();
				ans = min(ans, t);
			}
		}
		cout << ans << '\n';
	}
}