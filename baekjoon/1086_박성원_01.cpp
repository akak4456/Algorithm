//result:맞았습니다!!
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int N;
string digits[15];
int K;
long long int cache[1 << 15][100];
int S[15],p10[51];
long long int solve(int index, int taken, long long int mod) {
	if (index == N) {
		if (mod == 0)
			return 1;
		else
			return 0;
	}
	long long int& ret = cache[taken][mod];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int next = 0; next < N; next++) {
		if ((taken & (1 << next)) == 0) {
			int nextTaken = taken | (1 << next);
			long long int nextMod = (mod*p10[digits[next].size()]+S[next])%K;
			ret += solve(index + 1, nextTaken, nextMod);
		}
	}
	return ret;
}
long long int gcd(long long int a, long long int b) {
	long long int tmp, n;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < (1 << 15); i++)
		for (int j = 0; j < 100; j++)
			cache[i][j] = -1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> digits[i];
	}
	cin >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < digits[i].size(); j++) {
			S[i] = (S[i] * 10 + digits[i][j] - '0') % K;
		}
	}
	p10[0] = 1 % K;
	for (int i = 1; i <= 50; i++)
		p10[i] = p10[i - 1] * 10 % K;
	long long int ans = solve(0, 0, 0);
	if (ans == 0) {
		cout << "0/1\n";
	}
	else {
		long long int fac = 1;
		for (int i = 1; i <= N; i++)
			fac *= i;
		long long int g = gcd(fac, ans);
		cout << (ans / g) << '/' << (fac / g) << '\n';
	}
}