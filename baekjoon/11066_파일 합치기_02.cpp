//result:시간 초과
#include <iostream>
#include <vector>
using namespace std;
const int MAX_K = 501;
const int MAX_F = 20001;
int cache[MAX_K][MAX_F];

int minCost(vector<int> stat, int step, int prevCost) {
	//cout << stat.size() << endl;
	/*
	for (int i = 0; i < stat.size(); i++) {
		cout << stat[i] << ' ';
	}
	cout << endl;
	*/
	if (stat.size() == 1)
		return 0;
	int& ret = cache[step][prevCost];
	if (ret != 987654321)
		return ret;
	int sz = stat.size();
	for (int i = 0; i < sz; i++) {
		for (int j = i + 1; j < sz; j++) {
			vector<int> newStat;
			for (int t = 0; t < sz; t++) {
				if (t != i && t != j)
					newStat.push_back(stat[t]);
			}
			int cost = stat[i]+stat[j];
			newStat.push_back(cost);
			int ans = minCost(newStat,step+1,cost);
			if (cost + ans < ret) {
				ret = cost + ans;
			}
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < MAX_K; i++) {
			for (int j = 0; j < MAX_F; j++) {
				cache[i][j] = 987654321;
			}
		}
		int K;
		cin >> K;
		vector<int> stat;
		stat.resize(K);
		for (int i = 0; i < K; i++)
			cin >> stat[i];
		cout << minCost(stat , 0, 0) << '\n';
	}
}