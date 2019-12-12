//result:틀렸습니다
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];
string source, destination;
void t1(int sz1,int sz2) {
	for (int i = 1; i <= sz2; i++) {
		for (int j = 1; j <= sz1; j++) {
			int tmp = dp[i][j - 1];
			if (destination[i - 1] == source[j - 1]) {
				tmp++;
			}
			dp[i][j] = max(dp[i - 1][j], tmp);
		}
	}
}
void t2(int sz1, int sz2) {
	for (int i = 1; i <= sz2; i++) {
		for (int j = 1; j <= sz1; j++) {
			if (source[j - 1] == destination[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
}
void print(int sz1,int sz2) {
	for (int i = 0; i <= sz1; i++) {
		for (int j = 0; j <= sz2; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> source >> destination;
	int sz1 = source.size();
	int sz2 = destination.size();
	t1(sz1, sz2);
	//print(sz1,sz2);
	cout << dp[sz2][sz1] << '\n';
}
/*
반례
입력
ABBCC
ABACA
정답
dp
0 0 0 0 0 0
0 1 1 1 1 1
0 1 2 2 2 2
0 1 2 2 2 2
0 1 2 2 3 3
0 1 2 2 3 3
출력값:3
함수 t1
dp
0 0 0 0 0 0
0 1 1 1 1 1
0 1 2 3 3 3
0 1 2 3 3 3
0 1 2 3 4 5
0 1 2 3 4 5
출력값:5
*/