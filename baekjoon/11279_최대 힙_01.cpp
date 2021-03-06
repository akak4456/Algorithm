//result:시간 초과
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	priority_queue<int, vector<int>, less<> >pq;
	while (N--) {
		int t;
		cin >> t;
		if (t == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(t);
		}
	}
}