//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 10000;
int C;
int n,e[MAX_N],m[MAX_N];
int heat() {
	vector<pair<int, int> > order;
	for (int i = 0; i < n; i++) {
		order.push_back(make_pair(-e[i], i));
	}
	sort(order.begin(), order.end());
	int ret = 0, beginEat = 0;
	for (int i = 0; i < n; i++) {
		int box = order[i].second;
		beginEat += m[box];
		ret = max(ret, beginEat + e[box]);
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> m[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> e[i];
		}
		cout << heat() << endl;
	}
}