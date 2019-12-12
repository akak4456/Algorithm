//result:오답
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int C;
string W;
int N;
string F;
vector<string> results;
bool wildcard(int wIdx,int fIdx) {
	while (wIdx < W.size() && fIdx < F.size()) {
		if (W[wIdx] == '?' || W[wIdx] == F[fIdx]) {
			wIdx++;
			fIdx++;
		}
		else if (W[wIdx] == '*') {
			if (wIdx == W.size() - 1) {
				return true;
			}
			for (int i = 0; fIdx + i < F.size(); i++) {
				if (wildcard(wIdx + 1, fIdx + i)) {
					return true;
				}
			}
			return false;
		}
		else {
			return false;
		}
	}
	if (wIdx == W.size() && fIdx == F.size()) {
		return true;
	}
	else if (wIdx == W.size() - 1 && W[wIdx] == '*') {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cin >> C;
	while (C--) {
		cin >> W;
		cin >> N;
		while (N--) {
			cin >> F;
			if (wildcard(0,0)) {
				results.push_back(F);
			}
		}
	}
	sort(results.begin(), results.end());
	for (int i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}
}