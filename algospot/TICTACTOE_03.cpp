//result:정답
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
bool isWin(string state, char src) {
	if (state[0] == src && state[1] == src && state[2] == src)
		return true;
	if (state[3] == src && state[4] == src && state[5] == src)
		return true;
	if (state[6] == src && state[7] == src && state[8] == src)
		return true;
	if (state[0] == src && state[4] == src && state[8] == src)
		return true;
	if (state[2] == src && state[4] == src && state[6] == src)
		return true;
	if (state[0] == src && state[3] == src && state[6] == src)
		return true;
	if (state[1] == src && state[4] == src && state[7] == src)
		return true;
	if (state[2] == src && state[5] == src && state[8] == src)
		return true;
	return false;
}
int canWin(string state, char turn) {
	//turn에서 내가 이길꺼 같다:1 비길꺼 같다:0 질꺼 같다:-1
	//cout << state << ' ' << turn << endl;
	if (isWin(state, 'o' + 'x' - turn))
		return -1;
	bool isFinish = true;
	for (int i = 0;i < 9;i++) {
		if (state[i] == '.') {
			isFinish = false;
			break;
		}
	}
	if (isFinish) {
		return 0;
	}
	int ret = -1;
	for (int i = 0;i < 9;i++) {
		if (state[i] == '.') {
			string newState = state;
			newState[i] = turn;
			//cout << newState << endl;
			int ans = canWin(newState, 'o' + 'x' - turn);
			if (ans == -1) {
				return 1;
			}
			if (ans == 0) {
				ret = 0;
			}
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
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		int xCnt = 0, oCnt = 0;
		string src = s1 + s2 + s3;
		for (int i = 0;i < 9;i++) {
			if (src[i] == 'x')
				xCnt++;
			if (src[i] == 'o')
				oCnt++;
		}
		char startTurn;
		if (xCnt > oCnt) {
			startTurn = 'o';
		}
		else {
			startTurn = 'x';
		}
		int ans = canWin(src, startTurn);
		if (ans == 1) {
			cout << startTurn << "\n";
		}
		else if (ans == 0) {
			cout << "TIE\n";
		}
		else if (ans == -1) {
			if (startTurn == 'x') {
				cout << "o\n";
			}
			else {
				cout << "x\n";
			}
		}
	}
}