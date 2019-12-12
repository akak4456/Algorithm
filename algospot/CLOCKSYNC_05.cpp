//result:정답
#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;
int C;
int input[16];
int best;
vector<int> sw[10];
void solve(vector<int> cand) {
	if (cand.size() == 10) {
		int newInput[16];
		for (int i = 0; i < 16; i++)
			newInput[i] = input[i];
		int candSum = 0;
		for (int i = 0; i < 10; i++) {
			candSum += cand[i];
			for (int j = 0; j < sw[i].size(); j++) {
				newInput[sw[i][j]] += 3 * cand[i];
				if (newInput[sw[i][j]] > 12)
					newInput[sw[i][j]] -= 12;
			}
		}
		for (int i = 0; i < 16; i++) {
			if (newInput[i] != 12)
				return;
		}
		if (best > candSum)
			best = candSum;
		return;
	}
	for (int i = 0; i <= 3; i++) {
		cand.push_back(i);
		solve(cand);
		cand.pop_back();
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	sw[0] = { 0,1,2 };
	sw[1] = { 3, 7, 9, 11 };
	sw[2] = { 4, 10, 14, 15 };
	sw[3] = { 0, 4, 5, 6, 7 };
	sw[4] = { 6, 7, 8, 10, 12 };
	sw[5] = { 0, 2, 14, 15 };
	sw[6] = { 3, 14, 15 };
	sw[7] = { 4, 5, 7, 14, 15 };
	sw[8] = { 1, 2, 3, 4, 5 };
	sw[9] = { 3, 4, 5, 9, 13 };
	while (C--) {
		best = INF;
		for (int i = 0; i < 16; i++)
			cin >> input[i];
		vector<int> tmp;
		solve(tmp);
		if (best == INF)
			cout << "-1\n";
		else
			cout << best << '\n';
	}
}