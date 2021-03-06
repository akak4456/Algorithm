//result:정답
#include <iostream>
#include <algorithm>
using namespace std;
int C, n, s;
int cache[101][11];
int A[101], pSum[101], pSqSum[101];
const int INF = 987654321;
void precalc() {
	sort(A, A + n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for (int i = 1; i < n; i++) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1]+A[i]*A[i];
	}
}
int minError(int from, int to) {
	int sum = pSum[to] - (from == 0 ? 0 : pSum[from - 1]);
	int sqSum = pSqSum[to] - (from == 0 ? 0 : pSqSum[from - 1]);
	int m = int(0.5 + (double)sum / (to - from + 1));
	int ret = sqSum - 2 * m*sum + m * m*(to - from + 1);
	return ret;
}
int quantize(int from, int part) {
	if (from == n) {
		return 0;
	}
	if (part == 0) {
		return INF;
	}
	int& ret = cache[from][part];
	if (ret != -1) {
		return ret;
	}
	ret = INF;
	for (int partSize = 1; from + partSize <= n; partSize++) {
		ret = min(ret, minError(from, from + partSize - 1) + quantize(from + partSize, part - 1));
	}
	return ret;

}
int main() {
	cin >> C;
	while (C--) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 11; j++) {
				cache[i][j] = -1;
			}
		}
		cin >> n >> s;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		precalc();
		cout << quantize(0, s) << endl;
	}
}