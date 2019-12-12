//result:시간 초과
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<vector<int>, int>cache;
int minCost(vector<int> stat) {
	//cout << stat.size() << endl;
	/*
	for (int i = 0; i < stat.size(); i++) {
		cout << stat[i] << ' ';
	}
	cout << endl;
	*/
	if (stat.size() == 1)
		return 0;
	cout << cache.size() << endl;
	if (cache.find(stat) != cache.end()) {
		return cache.find(stat)->second;
	}
	int ret = 987654321;
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
			sort(newStat.begin(), newStat.end());
			int ans = minCost(newStat);
			cache.insert(make_pair(newStat, ans));
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
		cache.clear();
		int K;
		cin >> K;
		vector<int> stat;
		stat.resize(K);
		for (int i = 0; i < K; i++)
			cin >> stat[i];
		sort(stat.begin(), stat.end());
		cout << minCost(stat) << '\n';
	}
}