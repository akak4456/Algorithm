//result:시간초과
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int C;
int N, S;
int A[100];
int cache[100][10];
int minError(int from, int to) {
	int ret = INF;
	for (int i = 1; i <= 1000; i++) {
		int sum = 0;
		for (int j = from; j <= to; j++) {
			sum += (A[j] - i) * (A[j] - i);
		}
		ret = min(ret, sum);
	}
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
		sort(A, A + N);
		cout << quantize(0, S) << endl;
	}
}