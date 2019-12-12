//result:시간초과
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int m;
int cost[500][2];
vector<pair<int, int> > subtract;
int best;
void dfs(int costVal,vector<int> idx) {
	//cout << idx.size() << " "<<costVal << endl;
	for (int i = 0; i < subtract.size(); i++) {
		if (subtract[i].first < 0) {
			if (costVal + subtract[i].first == 0) {
				idx.push_back(subtract[i].second);
				int sum = 0;
				for (int j = 0; j < idx.size(); j++) {
					sum += cost[idx[j]][0];
				}
				if (sum < best) {
					best = sum;
				}
				idx.pop_back();
			}
			else if (costVal + subtract[i].first > 0) {
				idx.push_back(subtract[i].second);
				dfs(costVal + subtract[i].first, idx);
				idx.pop_back();
			}
		}
	}
}
void dfsAll() {
	for (int i = 0; i < subtract.size(); i++) {
		if (subtract[i].first > 0) {
			vector<int> tmp;
			tmp.push_back(subtract[i].second);
			dfs(subtract[i].first,tmp);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		cin >> m;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < 2; j++)
				cin >> cost[i][j];
		for (int i = 0; i < m; i++) {
			subtract.push_back(make_pair(cost[i][0] - cost[i][1], i));
		}
		sort(subtract.begin(), subtract.end());
		best = 987654321;
		for (int i = 0; i < subtract.size(); i++) {
			//cout << subtract[i].first << endl;
			if (subtract[i].first == 0) {
				if (cost[subtract[i].second][0] < best) {
					best = cost[subtract[i].second][0];
				}
				subtract.erase(subtract.begin() + i);
				i--;
			}
		}
		dfsAll();
		cout << best << endl;
	}
}