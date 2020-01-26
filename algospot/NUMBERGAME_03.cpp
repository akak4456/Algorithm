//result:정답
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
int winner(int start, int end, int player) {
	//cout << start << " " << end << " " << player << " " << score1 << " " << score2 << endl;
	//player = 0:현우 턴 player = 1:서하 턴
	if (end < start) {
		//기저사례
		return 0;
	}
	int& ret = cache[start][end][player];
	if (ret != -INF) return ret;
	if (player == 0) {
		ret = max(ret, arr[start]-winner(start + 1, end, player));
		ret = max(ret, arr[end]-winner(start, end - 1, player));
		if (end - start >= 1) {
			ret = max(ret, -winner(start + 2, end, player));
			ret = max(ret, -winner(start , end-2, player));
		}
	}
	else if (player == 1) {
		ret = INF;
		ret = min(ret, arr[start] - winner(start + 1, end, player));
		ret = min(ret, arr[end] - winner(start, end - 1, player));
		if (end - start >= 1) {
			ret = min(ret, -winner(start + 2, end, player));
			ret = min(ret, -winner(start, end - 2, player));
		}
	}
	return ret;
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
		cout << winner(0, n - 1, 0) << '\n';
	}
}