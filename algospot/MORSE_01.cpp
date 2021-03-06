//result:런타임 오류
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MOD = 1000000000 + 10;
int binom[101][101];
void getBinom() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (j == 0 || j == i)
				binom[i][j] = 1;
			else
				binom[i][j] = min(binom[i - 1][j - 1] + binom[i - 1][j],MOD);
		}
	}
}
string solve(int n,int m,int k) {
	//cout << n << ' ' << m << ' ' << k << endl;
	if (n == 0) {
		string tmp = "";
		for (int i = 0; i < m; i++) {
			tmp += 'o';
		}
		return tmp;
	}
	string ret = "";
	int skip = 0;
	int sum = 0;
	while (true) {
		if (k <= sum + binom[m + skip - 1][skip]) {
			break;
		}
		sum += binom[m + skip - 1][skip];
		skip++;
	}
	for (int i = 0; i < n - skip; i++) {
		ret += '-';
	}
	ret += 'o';
	return ret+solve(skip,m-1,k-sum);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getBinom();
	int C;
	cin >> C;
	while (C--) {
		int n, m, k;
		cin >> n >> m >> k;
		cout << solve(n,m,k) << '\n';
	}
}