//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int c;
int n, k;
int cn[1000], r[1000];
bool decision(double average) {
	vector<double> v;
	for (int i = 0; i < n; i++)
		v.push_back(average * cn[i] - r[i]);
	sort(v.begin(), v.end());
	double sum = 0;
	for (int i = n - k; i < n; i++) {
		sum += v[i];
	}
	return sum >= 0;
}
double optimize() {
	double lo = -1e-9, hi = 1;
	for (int iter = 0; iter < 100; iter++) {
		double mid = (lo + hi) / 2;

		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}
int main() {
	std::ios::sync_with_stdio(false);
	cout << fixed;
	cout.precision(10);
	cin >> c;
	while (c--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> r[i] >> cn[i];
		}
		cout << optimize() << endl;
	}
}