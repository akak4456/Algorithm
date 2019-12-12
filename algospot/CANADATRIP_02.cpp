//result:정답
#include <iostream>
#include <algorithm>
using namespace std;
int T;
int N, K;
struct City {
	int L;
	int M;
	int G;
};
City cities[5000];
bool decision(int dist) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (dist >= cities[i].L - cities[i].M) {
			ret += (min(dist, cities[i].L) - (cities[i].L - cities[i].M)) / cities[i].G + 1;
		}
	}
	return ret >= K;
}
int optimize() {
	int lo = -1, hi = 8100000;
	for (int i = 0; i < 100; i++) {
		int mid = (lo + hi) / 2;
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
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> cities[i].L >> cities[i].M >> cities[i].G;
		}
		cout << optimize() << endl;
	}
}