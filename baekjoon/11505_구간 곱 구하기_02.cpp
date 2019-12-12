//result:맞았습니다!!
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX_N = 1000000 + 1;
const int MOD = 1000000007;
int N, M,K;
ll seg[4 * MAX_N];
ll update(ll pos, ll val, ll node, ll x, ll y) {
	if (y < pos || pos < x)
		return seg[node];
	if (x == y)
		return seg[node] = val;
	ll mid = (x + y) >> 1;
	return seg[node]=(update(pos, val, node * 2, x, mid)*update(pos, val, node * 2 + 1, mid + 1, y)) % MOD;
}
ll query(ll lo, ll hi, ll node, ll x, ll y) {
	if (y < lo || hi < x)
		return 1;
	if (lo <= x && y <= hi)
		return seg[node];
	ll mid = (x + y) >> 1;
	return (query(lo, hi, node * 2, x, mid) * query(lo, hi, node * 2 + 1, mid + 1, y)) % MOD;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		update(i, t, 1, 1, N);
	}
	for (int i = 0; i < M + K; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1)
			update(y, z, 1, 1, N);
		else
			cout << query(y, z, 1, 1, N) << '\n';
	}
}