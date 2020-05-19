//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
const int MOD = 1000000000;
int fib[1000001];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		fib[i] += fib[i - 2];
		fib[i] %= MOD;
		fib[i] += fib[i - 1];
		fib[i] %= MOD;
	}
	if (n > 0) {
		cout << "1\n";
		cout << fib[n] << '\n';
	}
	else if (n == 0) {
		cout << "0\n0\n";
	}
	else {
		n *= -1;
		if (n % 2 == 1) {
			cout << "1\n";
			cout << fib[n] << '\n';
		}
		else {
			cout << "-1\n";
			cout << fib[n] << '\n';
		}
	}
}