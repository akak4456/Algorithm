//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
int T;
int N, K;
int D[MAXN+1];
int pSum[MAXN+1];
int waysToBuy() {
	const int MOD = 20091101;
	int ret = 0;
	vector<long long> count(K, 0);
	for (int i = 0; i <= N; i++)
		count[pSum[i]]++;
	for (int i = 0; i < K; i++) {
		if (count[i] >= 2)
			ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % MOD;
	}
	return ret;
}
int maxBuys() {
	vector<int> ret(N + 1, 0);
	vector<int> prev(K, -1);
	for (int i = 0; i <= N; i++) {
		if (i > 0) {
			ret[i] = ret[i - 1];
		}
		else {
			ret[i] = 0;
		}
		int loc = prev[pSum[i]];
		if (loc != -1) ret[i] = max(ret[i], ret[loc] + 1);
		prev[pSum[i]] = i;
	}
	return ret.back();
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> D[i];
		}
		pSum[0] = 0;
		for (int i = 1; i <= N; i++) {
			pSum[i] = (D[i-1] + pSum[i - 1])%K;
		}
		cout << waysToBuy() <<" " << maxBuys() << endl;
	}
}