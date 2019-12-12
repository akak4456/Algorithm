//result:맞았습니다!!
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int dp[1001][1001];
string source, destination;
void print(int sz2, int sz1) {
	for (int i = 0; i <= sz2; i++) {
		for (int j = 0; j <= sz1; j++) {
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
	cout << dp[sz2][sz1] << '\n';
	int x = sz1, y = sz2;
	//x:source y:destination
	//print(sz2, sz1);
	stack<char> st;
	while (dp[y][x]  != 0) {
		//cout << source[x - 1] << ' ' << destination[y - 1] << endl;
		if (dp[y][x] == dp[y - 1][x]) {
			y--;
		}
		else if (dp[y][x] == dp[y][x - 1]) {
			x--;
		}
		else {
			st.push(destination[y - 1]);
			y--;
			x--;
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << '\n';
}