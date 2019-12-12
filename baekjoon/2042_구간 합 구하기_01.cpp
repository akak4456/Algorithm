//result:맞았습니다!!
#include <iostream>
#include <vector>
using namespace std;
struct FenwickTree {
	vector<long long int> tree;
	FenwickTree(int n) :tree(n + 1) {}
	long long int sum(int pos) {
		pos++;
		long long int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos - 1);
		}
		return ret;
	}
	void add(int pos, int val) {
		pos++;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos & -pos);
		}
	}
};
const int MAX_N = 1000000 + 1;
int N, M,K;
int arr[MAX_N];
int dp[MAX_N];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	FenwickTree fenwickTree(N);
	for (int i = 0; i < N; i++) {
		fenwickTree.add(i, arr[i]);
	}
	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			fenwickTree.add(b - 1, -arr[b - 1]);
			fenwickTree.add(b - 1, c);
			arr[b - 1] = c;
		}
		else if (a == 2) {
			cout << fenwickTree.sum(c - 1) - fenwickTree.sum(b - 2) << '\n';
		}
	}
}