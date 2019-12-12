//result:Á¤´ä
#include <iostream>
#include <vector>
using namespace std;
struct FenwickTree {
	vector<long long int> tree;
	FenwickTree(int n) : tree(n + 1) {}
	long long int sum(int pos) {
		++pos;
		long long int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}
	void add(int pos, long long int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};
long long int countMoves(const vector<int>& A) {
	FenwickTree tree(1000000);
	long long int ret = 0;
	for (int i = 0; i < A.size(); i++) {
		ret += tree.sum(999999) - tree.sum(A[i]);
		tree.add(A[i], 1);
	}
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	int c, n;
	cin >> c;
	while (c--) {
		cin >> n;
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			a.push_back(t);
		}
		cout << countMoves(a) << endl;
	}
}