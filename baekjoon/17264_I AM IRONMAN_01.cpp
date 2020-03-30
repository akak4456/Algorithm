//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, P;
	int W, L, G;
	cin >> N >> P;
	cin >> W >> L >> G;
	pair<string, char> player[1000];
	bool isWin = false;
	int score = 0;
	for (int i = 0; i < P; i++)
		cin >> player[i].first >> player[i].second;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		bool find = false;
		for (int idx = 0; idx < P; idx++) {
			if (player[idx].first == str) {
				if (player[idx].second == 'W') {
					score += W;
				}
				else {
					score -= L;
				}
				find = true;
				break;
			}
		}
		if (!find)
			score -= L;
		if (score < 0)
			score = 0;
		if (score >= G) {
			isWin = true;
			break;
		}
		//cout << find << ' '<<score << endl;
	}
	if (isWin) {
		cout << "I AM NOT IRONMAN!!\n";
	}
	else {
		cout << "I AM IRONMAN!!\n";
	}
}