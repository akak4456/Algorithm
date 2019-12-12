//result:시간 초과
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<int, int> > timeTable;//end start
	for (int i = 0; i < N; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		timeTable.push_back(make_pair(t2, t1));
	}
	int cnt = 0;
	while (!timeTable.empty()) {
		cnt++;
		sort(timeTable.begin(), timeTable.end());
		int endTime = timeTable.begin()->first;
		int startTime = timeTable.begin()->second;
		timeTable.erase(timeTable.begin());
		for (int i = 0; i < timeTable.size(); i++) {
			int end = timeTable[i].first;
			int start = timeTable[i].second;
			if ((end > startTime && end < endTime) ||
				(start > startTime && start < endTime)) {
				timeTable.erase(timeTable.begin() + i);
				i--;
			}
		}
	}
	cout << cnt << '\n';
}