//result:오답
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int> > max_heap;
priority_queue<int, vector<int> > min_heap;
int C;
int N, a, b;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		while (!max_heap.empty()) {
			max_heap.pop();
		}
		while (!min_heap.empty()) {
			min_heap.pop();
		}
		cin >> N >> a >> b;
		int A = 1983;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (i%2 == 0) {
				max_heap.push(A);
			}
			else {
				min_heap.push(A);
			}
			if (max_heap.size() != 0 && min_heap.size() != 0) {
				int tmp1 = max_heap.top();
				int tmp2 = min_heap.top();
				if (tmp2 > tmp1) {
					max_heap.pop();
					min_heap.pop();
					max_heap.push(tmp2);
					min_heap.push(tmp1);
				}
			}
			sum += max_heap.top();
			A = (A * a + b) % 20090711;
		}
		cout << sum << endl;
	}
}