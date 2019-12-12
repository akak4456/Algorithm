//result:정답
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int C;
int N;
map<int, int> coords;
bool isDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.end()) return false;
	return y < it->second;
}
void removeDominated(int x, int y) {
	map<int, int>::iterator it = coords.upper_bound(x);
	if (it == coords.begin()) return;
	--it;
	while (true) {
		if (it->second > y)break;
		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}
	}
}
int registered(int x, int y) {
	if (isDominated(x, y)) return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		coords.clear();
		cin >> N;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			sum += registered(x, y);
		}
		cout << sum << endl;
	}
}