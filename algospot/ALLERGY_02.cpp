//result:시간초과
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int T;
int n, m;
vector<int> eaters[50];
vector<pair<string, int> > name;
int best;
void slowSearch(int food, vector<int>& edible, int chosen) {
	if (chosen >= best) return;
	if (food == m) {
		if (find(edible.begin(), edible.end(), 0) == edible.end()) {
			best = chosen;
		}
		return;
	}
	slowSearch(food + 1, edible, chosen);
	for (int j = 0; j < eaters[food].size(); j++) {
		edible[eaters[food][j]]++;
	}
	slowSearch(food + 1, edible, chosen + 1);
	for (int j = 0; j < eaters[food].size(); j++) {
		edible[eaters[food][j]]--;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		best = 987654321;
		for (int i = 0; i < 50; i++) {
			eaters[i].clear();
		}
		name.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			name.push_back(make_pair(tmp, i));
		}
		for (int i = 0; i < m; i++) {
			int t1;
			cin >> t1;
			while (t1--) {
				string t2;
				cin >> t2;
				auto it = find_if(name.begin(), name.end(), [&t2](const std::pair<std::string, int> & element) { return element.first == t2; });
				eaters[i].push_back(it->second);
			}
		}
		vector<int> e;
		e.resize(n);
		for (int i = 0; i < e.size(); i++) {
			e[i] = 0;
		}
		slowSearch(0, e, 0);
		cout << best << endl;
	}
}