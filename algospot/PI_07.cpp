//result:오답
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int cache[10001];
int calcDifficulty(string src) {
	bool isCan = true;
	for (int i = 1; i < src.size(); i++) {
		if (src[i] != src[0]) {
			isCan = false;
			break;
		}
	}
	if (isCan)
		return 1;
	isCan = true;
	char a = src[0], b = src[1];
	for (int i = 2; i < src.size(); i++) {
		if (i % 2 == 0) {
			if (src[i] != a) {
				isCan = false;
				break;
			}
		}
		else {
			if (src[i] != b) {
				isCan = false;
				break;
			}
		}
	}
	if (isCan)
		return 4;
	isCan = true;
	int diff = src[1] - src[0];
	for (int i = 1; i < src.size() - 1; i++) {
		if (src[i+1] - src[i] != diff) {
			isCan = false;
			break;
		}
	}
	if (isCan) {
		if (diff == 1 || diff == -1)
			return 2;
		else
			return 5;
	}
	return 10;
}
string query;
int solve(int idx) {
	if (query.size()-idx <= 5) {
		return calcDifficulty(query.substr(idx));
	}
	int& ret = cache[idx];
	if (ret != -1)
		return ret;
	ret = 987654321;
	int difficulty3 = solve(idx + 3);
	int difficulty4 = solve(idx + 4);
	int difficulty5 = solve(idx + 5);
	ret = min(ret, calcDifficulty(query.substr(idx, 3)) + difficulty3);
	ret = min(ret, calcDifficulty(query.substr(idx, 4)) + difficulty4);
	ret = min(ret, calcDifficulty(query.substr(idx, 5)) + difficulty5);
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));
		cin >> query;
		cout << solve(0) << '\n';
	}
}