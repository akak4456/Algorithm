//result:오답
#include <iostream>
#include <string>
using namespace std;
int C;
int N;
string state[101];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i <= N; i++) {
			cin >> state[i];
		}
		int cnt = 0;
		int sz = state[0].size();
		for (int i = 0; i < N; i++) {
			//cout << i << endl;
			string ans = state[i] + state[i];
			int begin = 0;
			for (begin = 0; begin < sz; begin++) {
				bool canBreak = true;
				for (int idx = 0; idx < sz; idx++) {
					if (ans[begin + idx] != state[i + 1][idx]) {
						canBreak = false;
						break;
					}
				}
				if (canBreak)
					break;
			}
			//cout << begin << endl;
			if (i % 2 == 0)
				cnt += sz-begin;
			else
				cnt += begin;
		}
		cout << cnt << endl;
	}
}