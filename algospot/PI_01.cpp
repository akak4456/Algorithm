//result:컴파일 실패
#include <iostream>
#include <string>
using namespace std;
int C;
string question;
int cache[10000][3];
int levelreturn(int idx, int len) {
	bool isCan = true;
	for (int i = 0; i < len-1; i++) {
		if (question[idx + i] != question[idx + i + 1]) {
			isCan = false;
			break;
		}
	}
	if (isCan) {
		return 1;
	}
	isCan = true;
	if (question[idx] - question[idx + 1] == 1) {
		for (int i = 1; i < len - 1; i++) {
			if (question[idx + i] - question[idx + i + 1] != 1) {
				isCan = false;
				break;
			}
		}
		if (isCan) {
			return 2;
		}
	}
	isCan = true;
	if (question[idx] - question[idx + 1] == -1) {
		for (int i = 1; i < len - 1; i++) {
			if (question[idx + i] - question[idx + i + 1] != -1) {
				isCan = false;
				break;
			}
		}
		if (isCan) {
			return 2;
		}
	}
	isCan = true;
	int a = question[idx];
	int b = question[idx + 1];
	for (int i = 2; i < len; i += 2) {
		if (question[idx + i] != a) {
			isCan = false;
			break;
		}
	}
	for (int i = 3; i < len; i += 2) {
		if (question[idx + i] != b) {
			isCan = false;
			break;
		}
	}
	if (isCan) {
		return 4;
	}
	isCan = true;
	int isGap = question[idx+1] - question[idx];
	for (int i = 1; i < len - 1; i++) {
		if (question[idx + 1 + i] - question[idx + i] != isGap) {
			isCan = false;
			break;
		}
	}
	if (isCan) {
		return 5;
	}
	return 10;
}
int solve(int idx, int len) {
	int& ret = cache[idx][len-3];
	if (ret != -1) {
		return ret;
	}
	int level = 0;
	if (idx + len -1 >= question.size()) {
		ret = levelreturn(idx,question.size()-idx);
	}
	else {
		int min = INT_MAX;
		int ans = solve(idx + len, 3);
		if (ans < min) {
			min = ans;
		}
		ans = solve(idx + len, 4);
		if (ans < min) {
			min = ans;
		}
		ans = solve(idx + len, 5);
		if (ans < min) {
			min = ans;
		}
		ret = levelreturn(idx, len) + ans;
	}
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(int) * 10000 * 3);
		cin >> question;
		int min = INT_MAX;
		int ans = solve(0, 3);
		if (ans < min) {
			min = ans;
		}
		ans = solve(0, 4);
		if (ans < min) {
			min = ans;
		}
		ans = solve(0, 5);
		if (ans < min) {
			min = ans;
		}
		cout << min << endl;
	}
}