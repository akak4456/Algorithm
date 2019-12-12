//result:시간 초과
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[500000];
int Q[500000];
int M;
int binarySearch(int start, int end, int q) {
	int left = start;
	int right = end;
	int ret = 0;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (A[middle] == q) {
			ret = 1;
			int tmp1 = middle - 1, tmp2 = middle + 1;
			while (A[tmp1] == q) {
				ret++;
				tmp1--;
			}
			while (A[tmp2] == q) {
				ret++;
				tmp2++;
			}
			break;
		}
		else if (A[middle] > q) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> Q[i];
	for (int i = 0; i < M; i++) {
		cout << binarySearch(0, N - 1, Q[i]) << ' ';
	}
	cout << '\n';
}