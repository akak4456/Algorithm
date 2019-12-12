//result:오답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C;
int N;
int H[20000];
int solve(int lo, int hi) {
	if (lo == hi) {
		return H[lo];
	}
	int mid = (lo + hi) / 2;
	int leftMax = solve(lo, mid);
	int rightMax = solve(mid + 1, hi);
	vector<pair<int, int> > bundle;
	if (H[mid] > H[mid + 1]) {
		bundle.push_back(make_pair(H[mid + 1], 2));
	}
	else {
		bundle.push_back(make_pair(H[mid], 2));
	}
	for (int i = mid + 1; i <= hi; i++) {
		if (H[i] >= bundle.back().first) {
			bundle.back().second++;
		}
		else {
			bundle.push_back(make_pair(H[i], bundle.back().first + 1));
		}
	}
	int lastIdx = 0;
	for (int i = mid - 1; i >= lo; i--) {
		if (H[i] >= bundle[lastIdx].first) {
			bundle[lastIdx].second++;
		}
		else {
			while (lastIdx+1 < bundle.size()&&bundle[lastIdx].first > H[i])
				lastIdx++;
			bundle[lastIdx].second++;
		}
	}
	int ret = max(leftMax,rightMax);
	for (int i = 0; i < bundle.size(); i++) {
		if (lo == 0 && hi == N - 1) {
			cout << bundle[i].first << ' ' << bundle[i].second << endl;
		}
		ret = max(ret, bundle[i].first * bundle[i].second);
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> H[i];
		}
		cout << solve(0, N - 1) << '\n';
	}
}