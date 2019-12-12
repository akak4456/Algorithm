//result:틀렸습니다
/*
fenwick tree로는 구간 곱을 구하기가 다소 어렵다
*/
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1000000 + 1;
const int MOD = 1000000007;
long long int mul(long long int  x, long long int y, long long int p) {
	long long int ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}
struct FenwickTree {
	vector<long long int> tree;
	FenwickTree(int n) :tree(n + 1) {
		for (int i = 0; i <= n; i++) {
			tree[i] = 1;
		}
	}
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
	long long int pmul(int pos) {
		pos++;
		long long int ret = 1;
		while (pos > 0) {
			ret = ((ret%MOD)*(tree[pos]%MOD))%MOD;
			pos &= (pos - 1);
		}
		return ret;
	}
	void multiply(int pos, int val) {
		pos++;
		while (pos < tree.size()) {
			tree[pos] = ((tree[pos] % MOD) * (val % MOD)) % MOD;
			pos += (pos & -pos);
		}
	}
	void divide(int pos, int val) {
		pos++;
		while (pos < tree.size()) {
			tree[pos] = ((tree[pos] % MOD)*(mul(val,MOD-2,MOD)%MOD)) % MOD;
			pos += (pos & -pos);
		}
	}
};
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
		fenwickTree.multiply(i, arr[i]);
	}
	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			fenwickTree.divide(b - 1, arr[b - 1]);
			fenwickTree.multiply(b - 1, c);
			arr[b - 1] = c;
		}
		else if (a == 2) {
			cout << (fenwickTree.pmul(c - 1) % MOD) * (mul(fenwickTree.pmul(b - 2), MOD - 2, MOD) % MOD) % MOD << '\n';
		}
	}
}