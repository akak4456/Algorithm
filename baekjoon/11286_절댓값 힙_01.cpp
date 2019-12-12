//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct absValue {
	int v;
	int absV;
};
bool operator<(absValue t, absValue u) {
	if (t.absV > u.absV) {
		return true;
	}
	else if (t.absV == u.absV) {
		return t.v > u.v;
	}
	else {
		return false;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<absValue>pq;
	while (N--) {
		int t;
		cin >> t;
		if (t == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top().v << '\n';
				pq.pop();
			}
		}
		else {
			absValue tmp;
			tmp.v = t;
			tmp.absV = abs(t);
			pq.push(tmp);
		}
	}
}