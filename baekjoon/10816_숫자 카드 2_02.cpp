//result:시간 초과
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[500000];
int Q[500000];
int M;
int ret = 0;
void binarySearch(int start, int end, int q) {
	int left = start;
	int right = end;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (A[middle] == q) {
			ret++;
			if (A[middle - 1] == q) {
				binarySearch(start, middle - 1, q);
			}
			if (A[middle + 1] == q) {
				binarySearch(middle + 1, end, q);
			}
			return;
		}
		else if (A[middle] > q) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
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
		binarySearch(0, N - 1, Q[i]);
		cout << ret << ' ';
		ret = 0;
	}
	cout << '\n';
}