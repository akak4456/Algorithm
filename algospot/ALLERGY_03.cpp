//result:정답
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int T;
int n, m;
vector<int> canEat[50], eaters[50];
vector<pair<string, int> > name;
int best;
void search(vector<int>& edible, int chosen) {
	if (chosen >= best) return;
	int first = 0;
	while (first < n && edible[first] > 0) first++;
	if (first == n) { best = chosen; return; }
	for (int i = 0; i < canEat[first].size(); i++) {
		int food = canEat[first][i];
		for (int j = 0; j < eaters[food].size(); j++) {
			edible[eaters[food][j]]++;
		}
		search(edible, chosen + 1);
		for (int j = 0; j < eaters[food].size(); j++) {
			edible[eaters[food][j]]--;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		best = 987654321;
		for (int i = 0; i < 50; i++) {
			eaters[i].clear();
			canEat[i].clear();
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
				canEat[it->second].push_back(i);
			}
		}
		vector<int> e;
		e.resize(n);
		for (int i = 0; i < e.size(); i++) {
			e[i] = 0;
		}
		search(e, 0);
		cout << best << endl;
	}
}