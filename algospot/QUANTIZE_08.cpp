//result:시간초과
/*
시간초과가 뜬 이유
minError를 구하는 것이 오래 걸린다. 그래서 시간 초과가 뜸
*/
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
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}
int minError(int lo, int hi) {
	int ret = INF;
	for (int num = 1; num <= 1000; num++) {
		int sum = 0;
		for (int i = lo; i <= hi; i++) {
			sum += (A[i] - num) * (A[i] - num);
		}
		ret = min(ret, sum);
	}
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