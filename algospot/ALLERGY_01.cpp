//result:런타임 오류
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int T;
int n, m;
vector<vector<string> > food;
vector<string> friends;
int best;
void choose(int count) {
	if (friends.empty()) {
		best = min(best, count);
		return;
	}
	int MAX = -1;
	vector<vector<string> > cand;
	sort(friends.begin(), friends.end());
	for (int i = 0; i < m; i++) {
		vector<string> result;
		result.clear();
		result.resize(friends.size() + food[i].size());//공간확보
		auto itr = set_intersection(friends.begin(), friends.end(), food[i].begin(), food[i].end(), result.begin());//교집합
		result.erase(itr, result.end());
		int c = result.size();
		if (c > MAX) {
			cand.clear();
			cand.push_back(food[i]);
			MAX = c;
		}
		else if (c == MAX) {
			cand.push_back(food[i]);
		}
	}
	for (int i = 0; i < cand.size(); i++) {
		vector<string> remain;
		for (int j = 0; j < cand[i].size(); j++) {
			for (int k = 0; k < friends.size(); k++) {
				if (cand[i][j] == friends[k]) {
					remain.push_back(friends[k]);
					friends.erase(friends.begin() + k);
					k--;
				}
			}
		}
		choose(count + 1);
		for (int j = 0; j < remain.size(); j++) {
			friends.push_back(remain[j]);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		best = 987654321;
		food.clear();
		while (!friends.empty()) {
			friends.erase(friends.begin());
		}
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			friends.push_back(tmp);
		}
		for (int i = 0; i < m; i++) {
			vector<string> tmp;
			int t1;
			cin >> t1;
			for (int j = 0; j < t1; j++) {
				string t2;
				cin >> t2;
				tmp.push_back(t2);
			}
			food.push_back(tmp);
		}
		choose(0);
		cout << best << endl;
	}
}