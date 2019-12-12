//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 987654321000;
const int MAX_N = 1000000 + 1;
int N, M;
ll minSeg[4 * MAX_N];
ll maxSeg[4 * MAX_N];
ll minUpdate(ll pos, ll val, ll node, ll x, ll y) {
	if (y < pos || pos < x)
		return minSeg[node];
	if (x == y)
		return minSeg[node] = val;
	ll mid = (x + y) >> 1;
	return minSeg[node]=min(minUpdate(pos, val, node * 2, x, mid),minUpdate(pos, val, node * 2 + 1, mid + 1, y));
}
ll maxUpdate(ll pos, ll val, ll node, ll x, ll y) {
	if (y < pos || pos < x)
		return maxSeg[node];
	if (x == y)
		return maxSeg[node] = val;
	ll mid = (x + y) >> 1;
	return maxSeg[node] = max(maxUpdate(pos, val, node * 2, x, mid), maxUpdate(pos, val, node * 2 + 1, mid + 1, y));
}
ll minQuery(ll lo, ll hi, ll node, ll x, ll y) {
	if (y < lo || hi < x)
		return INF;
	if (lo <= x && y <= hi)
		return minSeg[node];
	ll mid = (x + y) >> 1;
	return min(minQuery(lo, hi, node * 2, x, mid) , minQuery(lo, hi, node * 2 + 1, mid + 1, y));
}
ll maxQuery(ll lo, ll hi, ll node, ll x, ll y) {
	if (y < lo || hi < x)
		return -INF;
	if (lo <= x && y <= hi)
		return maxSeg[node];
	ll mid = (x + y) >> 1;
	return max(maxQuery(lo, hi, node * 2, x, mid), maxQuery(lo, hi, node * 2 + 1, mid + 1, y));
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		minUpdate(i, t, 1, 1, N);
		maxUpdate(i, t, 1, 1, N);
	}
	for (int i = 0; i < M ; i++) {
		int y, z;
		cin >> y >> z;
		cout << minQuery(y, z, 1, 1, N) << ' ' << maxQuery(y,z,1,1,N) << '\n';
	}
}