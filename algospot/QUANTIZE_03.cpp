//result:정답
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int C;
int N, S;
int A[100],pSum[100],pSqSum[100];
int cache[100][10];
void precalc() {
	sort(A, A + N);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for (int i = 1; i < N; i++) {
		pSum[i] = pSum[i - 1] + A[i];
		pSqSum[i] = pSqSum[i - 1] + A[i] * A[i];
	}
}
int minError(int lo, int hi) {
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo - 1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo - 1]);

	int m = int(0.5 + (double)sum / (hi - lo + 1));
	int ret = sqSum - 2 * m * sum + m * m * (hi - lo + 1);
	return ret;
}
int quantize(int from, int parts) {
	if (from == N) {
		return 0;
	}
	if (parts == 0)
		return INF;
	int& ret = cache[from][parts];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int size = 1; size <= N - from; size++) {
		ret = min(ret, minError(from, from + size - 1) + quantize(from + size, parts - 1));
	}
	return ret;
}
int main() {
	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));
		cin >> N >> S;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		precalc();
		cout << quantize(0, S) << endl;
	}
}