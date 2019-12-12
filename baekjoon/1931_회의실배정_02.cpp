//result:맞았습니다!!
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
	int idx = 0;
	sort(timeTable.begin(), timeTable.end());
	while (idx < N) {
		cnt++;
		int startIdx = idx;
		idx++;
		while (idx < N&&timeTable[startIdx].first > timeTable[idx].second) {
			idx++;
		}
	}
	cout << cnt << '\n';
}