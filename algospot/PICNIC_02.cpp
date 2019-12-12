//result:정답
#include <iostream>
#include <vector>
using namespace std;
int C;
int N, M;
vector<pair<int, int> > friends;
bool isMatched[10];
int cnt;
void solve(int startIdx) {
	bool isAllTrue = true;
	for (int i = 0; i < N; i++) {
		if (!isMatched[i]) {
			isAllTrue = false;
			break;
		}
	}
	if (isAllTrue) {
		cnt++;
		return;
	}
	for (int i = startIdx; i < friends.size(); i++) {
		if (!isMatched[friends[i].first] && !isMatched[friends[i].second]) {
			isMatched[friends[i].first] = true;
			isMatched[friends[i].second] = true;
			solve(i + 1);
			isMatched[friends[i].first] = false;
			isMatched[friends[i].second] = false;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		for (int i = 0; i < 10; i++)
			isMatched[i] = false;
		cnt = 0;
		cin >> N >> M;
		friends.resize(M);
		for (int i = 0; i < M; i++) {
			cin >> friends[i].first >> friends[i].second;
			if (friends[i].second < friends[i].first) {
				int tmp = friends[i].first;
				friends[i].first = friends[i].second;
				friends[i].second = tmp;
			}
		}
		solve(0);
		cout << cnt << '\n';
	}
}