//result:정답
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <map>
using namespace std;
map<vector<int>, int> toSort;
void precalc(int n) {
	vector<int> perm(n);
	for (int i = 0; i < n; i++) perm[i] = i;
	queue<vector<int> >q;
	q.push(perm);
	toSort[perm] = 0;
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
			if (perm[j] < perm[i])
				smaller++;
			fixed[i] = smaller;
		}
	}
	if (n < 8) {
		for (int i = n; i < 8; i++) {
			fixed.push_back(i);
		}
	}
	return toSort[fixed];
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	cin >> test_case;
	precalc(8);
	while (test_case--) {
		int N;
		cin >> N;
		vector<int> input;
		input.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}
		cout << solve(input) << '\n';
	}
}