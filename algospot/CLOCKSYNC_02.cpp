//result:오답
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int INF = 9999;
int C;
int switchToClock[10][5] = {
	{0,1,2,-1,-1},
	{3,7,9,11,-1},
	{4,10,14,15,-1},
	{0,4,5,6,7},
	{6,7,8,10,12},
	{0,2,14,15,-1},
	{3,14,15,-1,-1},
	{4,5,7,14,15},
	{1,2,3,4,5},
	{3,4,5,9,13}
};
int clocksync(int clock[],int swtch) {
	if (swtch == 9) {
		bool ok = true;
		for (int i = 0; i < 16; i++) {
			if (clock[i] != 12) {
				ok = false;
			}
		}
		if (ok) {
			return 0;
		}
		else {
			return INF;
		}
	}
	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		int tmp = cnt + clocksync(clock, swtch + 1);
		if (ret > tmp) {
			ret = tmp;
		}
		for (int i = 0; i < 5; i++) {
			if (switchToClock[swtch][i] != -1) {
				clock[switchToClock[swtch][i]] += 3;
				if (clock[switchToClock[swtch][i]] == 15) {
					clock[switchToClock[swtch][i]] = 3;
				}
			}
		}
	}
	return ret;
}
int main() {
	cin >> C;
	for (int i = 1; i <= C; i++) {
		int clock[16];
		for (int j = 0; j < 16; j++) {
			int t;
			cin >> t;
			clock[j] = t;
		}
		int sol = clocksync(clock, 0);
		if (sol == INF) {
			cout << -1 << endl;
		}
		else {
			cout << sol << endl;
		}
	}
}