//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int dp1[3];
int dp2[3];
int dp3[3];
int N;
int arr[1001][3];
void solve(int a[3]) {
	for (int i = 2; i <= N - 1; i++) {
		int ir = a[0], ig = a[1], ib = a[2];
		a[0] = min(INF,arr[i][0] + min(ig, ib));
		a[1] = min(INF,arr[i][1] + min(ir, ib));
		a[2] = min(INF,arr[i][2] + min(ir, ig));
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	int ans = INF;
	dp1[0] = arr[1][0];
	dp1[1] = INF;
	dp1[2] = INF;
	solve(dp1);
	ans = min(ans, min(arr[N][1] + min(dp1[0], dp1[2]), arr[N][2] + min(dp1[0], dp1[1])));

	dp2[0] = INF;
	dp2[1] = arr[1][1];
	dp2[2] = INF;
	solve(dp2);
	ans = min(ans, min(arr[N][0] + min(dp2[1], dp2[2]), arr[N][2] + min(dp2[0], dp2[1])));

	dp3[0] = INF;
	dp3[1] = INF;
	dp3[2] = arr[1][2];
	solve(dp3);
	ans = min(ans, min(arr[N][0] + min(dp3[1], dp3[2]), arr[N][1] + min(dp3[0], dp3[2])));
	cout << ans << '\n';
	return 0;
}