//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<int,vector<int>,less<int>>maxHeap;
	priority_queue<int, vector<int>, greater<int>>minHeap;
	while (N--) {
		int t;
		cin >> t;
		if (maxHeap.size() == minHeap.size()) {
			maxHeap.push(t);
		}
		else {
			minHeap.push(t);
		}
		if (!maxHeap.empty()&&!minHeap.empty()&&maxHeap.top() > minHeap.top()) {
			int tmp1 = maxHeap.top();
			int tmp2 = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			maxHeap.push(tmp2);
			minHeap.push(tmp1);
		}
		cout << maxHeap.top() << '\n';
	}
}