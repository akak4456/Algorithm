//result:맞았습니다!!
#include <iostream>
#include <deque>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	deque<int> dq;
	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}
	int cntSum = 0;
	while (M--) {
		int t;
		cin >> t;
		int index = 1;
		int sz = dq.size();
		for (deque<int>::iterator it = dq.begin(); it != dq.end(); it++) {
			if (*it == t)break;
			index++;
		}
		int left = index - 1;
		int right = sz - index + 1;
		if (left < right) {
			while (t != dq.front()) {
				cntSum++;
				dq.push_back(dq.front());
				dq.pop_front();
			}
			dq.pop_front();
		}
		else {
			while (t != dq.front()) {
				cntSum++;
				dq.push_front(dq.back());
				dq.pop_back();
			}
			dq.pop_front();
		}
	}
	cout << cntSum << '\n';
}