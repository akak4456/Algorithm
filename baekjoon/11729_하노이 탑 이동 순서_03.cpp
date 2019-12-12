//result:틀렸습니다
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cnt = 0;
vector<pair<int, int > > result;
void hanoi(int startNum, int endNum, int from, int to) {
	if (startNum == endNum) {
		result.push_back(make_pair(from, to));
		//cout << from << ' ' << to << endl;
		cnt++;
		return;
	}
	int nextTo = 1;
	if (from == 1) {
		if (to == 3)
			nextTo = 2;
		else if (to == 2)
			nextTo = 3;
	}
	else if (from == 2) {
		if (to == 3) {
			nextTo = 1;
		}
	}
	hanoi(startNum, endNum - 1, from, nextTo);
	hanoi(endNum, endNum, from, to);
	hanoi(startNum, endNum - 1, nextTo, to);
}
int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	hanoi(1, n, 1, 3);
	cout << cnt << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i].first << ' ' << result[i].second << '\n';
	;
}