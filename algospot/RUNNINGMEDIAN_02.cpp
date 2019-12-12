//result:정답
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, less<int> > max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;
int C;
int N, a, b;
struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) :a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};
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
		RNG rng(a,b);
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (max_heap.size() == min_heap.size())
				max_heap.push(rng.next());
			else
				min_heap.push(rng.next());
			if (max_heap.size() != 0 && min_heap.size() != 0) {
				int tmp1 = max_heap.top();
				int tmp2 = min_heap.top();
				if (tmp2 < tmp1) {
					max_heap.pop();
					min_heap.pop();
					max_heap.push(tmp2);
					min_heap.push(tmp1);
				}
			}
			sum = (sum+max_heap.top())%20090711;
		}
		cout << sum << endl;
	}
}