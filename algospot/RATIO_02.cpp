//result:오답
#include <iostream>
using namespace std;
int T;
double N, M;
int RATIO;
bool decision(long long int x) {
	int newRATIO = (M + x) * 100 / (N + x);
	return newRATIO > RATIO;
}
int optimize() {
	long long int lo = 0, hi = 2000000000;
	for (int i = 0; i < 100; i++) {
		long long int mid = (lo + hi) / 2;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		RATIO = M / N * 100;
		//cout << RATIO << endl;
		long long int ans = optimize();
		if (ans == 2000000000)
			cout << -1 << endl;
		else
			cout << optimize() << endl;
	}
}