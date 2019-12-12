//result:정답
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
void push(int clock[], int swtch, int forCount) {
	for (int i = 0; i < forCount; i++) {
		for (int j = 0; j < 5; j++) {
			if (switchToClock[swtch][j] != -1) {
				clock[switchToClock[swtch][j]] += 3;
				if (clock[switchToClock[swtch][j]] == 15) {
					clock[switchToClock[swtch][j]] = 3;
				}
			}
		}
	}
}
int switchCount[10] = { 0,0,0,0,0,0,0,0,0,0 };
int main() {
	cin >> C;
	for (int i = 1; i <= C; i++) {
		int clock[16];
		for (int j = 0; j < 16; j++) {
			int t;
			cin >> t;
			clock[j] = t;
		}
		for (int j = 0; j < 10; j++) {
			switchCount[j] = 0;
		}
		int sol = -1;
		while(true){
			switchCount[0]++;
			for (int j = 0; j < 10; j++) {
				if (switchCount[j] >= 4) {
					switchCount[j] = 0;
					switchCount[j + 1]++;
				}
			}
			int dupClock[16];
			for (int j = 0; j < 16; j++) {
				dupClock[j] = clock[j];
			}
			for (int j = 0; j < 10; j++) {
				push(dupClock, j, switchCount[j]);
			}
			bool ok = true;
			for (int j = 0; j < 16; j++) {
				if (dupClock[j] != 12) {
					ok = false;
				}
			}
			int cnt = 0;
			for (int j = 0; j < 10; j++) {
				cnt += switchCount[j];
			}
			if (ok) {
				if (sol == -1) {
					sol = cnt;
				}
				else if (sol > cnt) {
					sol = cnt;
				}
			}
			if (cnt >= 30) {
				break;
			}
		}
		cout << sol << endl;
	}
}