//result:정답
#include <iostream>
using namespace std;
int C;
int N, L;
int cost[1000];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> N >> L;
		for (int i = 0; i < N; i++) {
			cin >> cost[i];
		}
		double minValue = 987654321;
		for (int len = L; len <= N; len++) {
			for (int idx = 0; idx + len <= N; idx++) {
				double costSum = 0;
				for (int i = idx; i < idx + len; i++) {
					costSum += cost[i];
				}
				if (costSum / len < minValue) {
					minValue = (costSum * 1.0) / (len * 1.0);
				}
			}
		}
		cout << fixed;
		cout.precision(10);
		cout << minValue << '\n';
	}
}