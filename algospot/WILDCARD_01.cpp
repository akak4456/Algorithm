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
bool wildcard() {
	int wIdx = 0;
	int fIdx = 0;
	while (wIdx < W.size() && fIdx < F.size()) {
		if (W[wIdx] == '?') {
			wIdx++;
			fIdx++;
		}
		else if (W[wIdx] == '*') {
			while (fIdx < F.size() && W[wIdx + 1] != F[fIdx]) {
				fIdx++;
			}
			wIdx++;
		}
		else if (W[wIdx] == F[fIdx]) {
			wIdx++;
			fIdx++;
		}
		else {
			return false;
		}
	}
	if (wIdx == W.size() && fIdx == F.size()||W[wIdx] == '*') {
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
			if (wildcard()) {
				cout << "match" << endl;
				results.push_back(F);
			}
		}
	}
	sort(results.begin(), results.end());
	for (int i = 0; i < results.size(); i++) {
		cout << results[i] << endl;
	}
}