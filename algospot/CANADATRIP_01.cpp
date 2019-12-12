//result:시간초과
#include <iostream>
using namespace std;
int T;
int N, K;
struct City {
	int L;
	int M;
	int G;
};
City cities[5000];
bool decision(double mid) {
	int C = 0;
	for (int i = 0; i < N; i++) {
		int L = cities[i].L;
		int M = cities[i].M;
		int G = cities[i].G;
		if (L - M < mid)
			C++;
		while (L-M < mid&& M > 0) {
			M -= G;
			C++;
		}
	}
	//cout << mid << " " << C << endl;
	return C > K;
}
int optimize() {
	double lo = 0, hi = 8100000;
	for (int i = 0; i < 100; i++) {
		double mid = (lo + hi) / 2.0;
		if (decision(mid)) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	return (int)lo;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> cities[i].L >> cities[i].M >> cities[i].G;
		}
		cout << optimize() << endl;
	}
}