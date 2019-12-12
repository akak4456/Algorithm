//result:런타임 오류
#include <iostream>
#include <list>
using namespace std;
int C;
int N;
pair<int, int> time1[100];
pair<int, int> time2[100];
list<pair<int, int> > range;
bool dfs(int depth) {
	if (range.size() == 0) {
		range.push_back(time1[depth]);
		if (dfs(depth + 1))
			return true;
		range.pop_back();
		range.push_back(time2[depth]);
		if (dfs(depth + 1))
			return true;
		range.pop_back();
	}
	else {
		for (list<pair<int, int> >::iterator it = range.begin(); it != range.end(); it++) {
			if (time1[depth].second < (*it).first) {
				it = range.insert(it, time1[depth]);
				if (dfs(depth + 1))
					return true;
				it--;
				it = range.erase(it);
			}
			if (time2[depth].second < (*it).first) {
				it = range.insert(it, time2[depth]);
				if (dfs(depth + 1))
					return true;
				it--;
				it = range.erase(it);
			}
			if ((*it).second < time1[depth].first) {
				it++;
				it = range.insert(it, time1[depth]);
				if (dfs(depth + 1))
					return true;
				it--;
				it = range.erase(it);
			}
			if ((*it).second < time2[depth].first) {
				it++;
				it = range.insert(it, time2[depth]);
				if (dfs(depth + 1))
					return true;
				it--;
				it = range.erase(it);
			}
		}
	}
	return false;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> time1[i].first >> time1[i].second >> time2[i].first >> time2[i].second;
		}
		cout << dfs(0) << endl;
	}
}