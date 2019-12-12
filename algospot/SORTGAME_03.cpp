//result:시간초과
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

map<vector<int>, int> toSort;
void precalc(int n) {
	vector<int> perm(n);
	for (int i = 0; i < n; i++) {
		perm[i] = i;
	}
	queue<vector<int> > q;
	q.push(perm);
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		int cost = toSort[here];
		for (int i = 0; i < n; i++) {
			for (int j = i + 2; j <= n; j++) {
				reverse(here.begin() + i, here.begin() + j);
				if (toSort.count(here) == 0) {
					toSort[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
}
int solve(const vector<int>& perm) {
	int n = perm.size();
	vector<int> fixed(n);
	for (int i = 0; i < n; i++) {
		int smaller = 0;
		for (int j = 0; j < n; j++) {
			if (perm[j] < perm[i]) {
				smaller++;
			}
		}
		fixed[i] = smaller;
	}
	return toSort[fixed];
}
int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		toSort.clear();
		int n;
		cin >> n;
		vector<int> input(8);
		for (int i = 0; i < n; i++) {
			cin >> input[i];
		}
		precalc(n);
		cout << solve(input) << endl;
	}
}