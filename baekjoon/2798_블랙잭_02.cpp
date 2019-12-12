//result:맞았습니다!!
#include <iostream>
#include <cmath>
using namespace std;
int card[100];
int main() {
	std::ios::sync_with_stdio(false);
	int N,M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> card[i];
	int minDiff = 987654321;
	int minValue = -1;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = card[i] + card[j] + card[k];
				if (M >= sum && M - sum < minDiff) {
					minDiff = M - sum;
					minValue = sum;
				}
			}
		}
	}
	cout << minValue << endl;
}