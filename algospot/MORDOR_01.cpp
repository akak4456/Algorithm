//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 987654321;
const int MIN = -987654321;
struct RMQ {
	int n;
	vector<int> rangeMin;
	vector<int> rangeMax;
	RMQ(const vector<int>& array) {
		n = array.size();
		rangeMin.resize(n * 4);
		rangeMax.resize(n * 4);
		init(array, 0, n - 1, 1);
		init2(array, 0, n - 1, 1);
	}
	int init(const vector<int>& array, int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return MAX;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}

	int init2(const vector<int>& array, int left, int right, int node) {
		if (left == right)
			return rangeMax[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init2(array, left, mid, node * 2);
		int rightMin = init2(array, mid + 1, right, node * 2 + 1);
		return rangeMax[node] = max(leftMin, rightMin);
	}
	int query2(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return MIN;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMax[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return max(query2(left, right, node * 2, nodeLeft, mid), query2(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	int query2(int left, int right) {
		return query2(left, right, 1, 0, n - 1);
	}
};
int C;
int N, Q;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N >> Q;
		vector<int> arr;
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			arr.push_back(t);
		}
		RMQ rmq(arr);
		for (int i = 0; i < Q; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			cout << rmq.query2(t1, t2) - rmq.query(t1, t2) << endl;
		}
	}
}