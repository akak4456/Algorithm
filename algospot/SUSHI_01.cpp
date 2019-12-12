//result:정답
#include <iostream>
#include <algorithm>
using namespace std;
int C;
int N, M;
int price[20];
int pref[20];
int c[201];
int sushi() {
	int ret = 0;
	c[0] = 0;
	for (int budget = 1; budget <= M; budget++) {
		int cand = 0;
		for (int dish = 0; dish < N; dish++) {
			if (budget >= price[dish]) {
				cand = max(cand, c[(budget - price[dish])%201] + pref[dish]);
			}
		}
		c[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> price[i] >> pref[i];
			price[i] /= 100;
		}
		M /= 100;
		cout << sushi() << endl;
	}
}