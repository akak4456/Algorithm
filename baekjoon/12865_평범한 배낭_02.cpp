//result:틀렸습니다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int dp[100001];
vector<pair<int, int> > arr;
int solve(int w,int pos) {
	int& ret = dp[w];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = pos+1; i < arr.size(); i++) {
		//cout << w << ' ' << w - arr[i].first << endl;
		if (w - arr[i].first >= 0) {
			ret = max(ret, solve(w - arr[i].first,i)+arr[i].second);
			//cout << "ret:" << ret << endl;
		}
		//cout << "ret:" << ret << endl;
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < 100001; i++)
		dp[i] = -1;
	for (int i = 0; i < N; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		arr.push_back(make_pair(t1, t2));
	}
	cout << solve(K,0) << '\n';
}