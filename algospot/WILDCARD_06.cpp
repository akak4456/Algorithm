//result:오답
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int cache[101][101];
int C, N;
string wild, src;

int solve(int wildStart, int srcStart) {
	int dist = 0;
	int& ret = cache[wildStart][srcStart];
	if (ret != -1)
		return ret;
	ret = 0;
	while (wildStart+dist < wild.size() && srcStart+dist < src.size()&&(wild[wildStart + dist] == src[srcStart + dist]|| wild[wildStart + dist] == '?')) {
		dist++;
	}
	if (wildStart + dist == wild.size()) {
		if (srcStart + dist == src.size())
			return ret = 1;
		else
			return ret = 0;
	}
	if (wild[wildStart + dist] == '*') {
		for (int idx = srcStart + dist; idx <= src.size(); idx++) {
			if (solve(wildStart + dist + 1, idx) == 1) {
				return ret = 1;
			}
		}
		return ret = 0;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> wild;
		cin >> N;
		vector<string> ans;
		for (int i = 0; i < N; i++) {
			memset(cache, -1, sizeof(cache));
			cin >> src;
			if (solve(0, 0) == 1) {
				ans.push_back(src);
			}
		}
		sort(ans.begin(), ans.end());
		for (string str : ans) {
			cout << str << '\n';
		}
	}
}