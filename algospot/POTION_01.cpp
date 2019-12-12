//result:정답
#include <iostream>
#include <algorithm>
using namespace std;
int c;
int n;
int r[200];
int p[200];
int gcd(int p, int q) {
	if (q == 0) return p;
	return gcd(q, p % q);
}
int ceil(int a, int b) {
	return (a + b - 1) / b;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> r[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		int g = r[0];
		for (int i = 1; i < n; i++)
			g = gcd(g, r[i]);
		int a = g;
		for (int i = 0; i < n; i++)
			a = max(a, ceil(p[i] * g, r[i]));
		for (int i = 0; i < n; i++)
			cout << r[i] * a / g - p[i] << " ";
		cout << endl;
	}
}