//result:시간초과
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 987654321;
int n;
int arr[50];
int cache[50][50][2];
int best = -INF;
int winner(int start, int end, int player, int score1, int score2) {
	//cout << start << " " << end << " " << player << " " << score1 << " " << score2 << endl;
	//player = 0:현우 턴 player = 1:서하 턴
	if (end < start) {
		//기저사례
		if (player == 0) {
			best = max(best, score1 - score2);
		}
		else {
			best = max(best, score2 - score1);
		}
		return 0;
		/*
		if (player == 0) {
			//cout << "player0:" << score2 - score1 << endl;
			return score1-score2;
		}
		else if (player == 1) {
			//cout << "player1:" << score1 - score2 << endl;
			return score2-score1;
		}
		*/
	}

	if (player == 0) {
		winner(start + 1, end, 1, score1 + arr[start], score2);
		winner(start, end - 1, 1, score1 + arr[end], score2);
		if (end - start >= 1) {
			winner(start + 2, end, 1, score1, score2);
			winner(start , end-2, 1, score1, score2);
		}
	}
	else {
		winner(start + 1, end, 0, score1 , score2 + arr[start]);
		winner(start, end - 1, 0, score1 , score2 + arr[end]);
		if (end - start >= 1) {
			winner(start + 2, end, 0, score1, score2);
			winner(start, end - 2, 0, score1, score2);
		}
	}
	return 0;
	/*
	int add1 = 0, add2 = 0;
	if (player == 0) {
		add1 = arr[start];
	}
	else {
		add2 = arr[start];
	}
	ret = max(ret, -winner(start + 1, end, 1 - player, score1 + add1, score2 + add2));

	add1 = 0;
	add2 = 0;
	if (player == 0) {
		add1 = arr[end];
	}
	else {
		add2 = arr[end];
	}
	ret = max(ret, -winner( start, end - 1, 1 - player, score1 + add1, score2+add2));
	if (end - start >= 1) {
		ret = max(ret, -winner(start + 2, end, 1 - player, score1, score2));
		ret = max(ret, -winner(start, end - 2, 1 - player, score1, score2));
	}
	cout << "player"<<player<<" ret: " << ret << endl;
	return ret;
	*/
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0;i < 50;i++) {
			for (int j = 0;j < 50;j++) {
				for (int k = 0;k < 2;k++) {
					cache[i][j][k] = -INF;
				}
			}
		}
		cin >> n;
		for (int i = 0;i < n;i++)
			cin >> arr[i];
		winner(0, n - 1, 0, 0, 0);
		cout << best << '\n';
	}
}