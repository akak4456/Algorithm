//result:시간 초과
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[500000];
int Q[500000];
int M;
int leftIdx, rightIdx;
int binarySearch(int start, int end, int q) {
	int left = start;
	int right = end;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (A[middle] == q) {
			if (A[middle - 1] != q) {
				leftIdx = middle;
				
			}
			else {
				binarySearch(left, middle - 1, q);
			}
			if (A[middle + 1] != q) {
				rightIdx = middle;
				
			}
			else {
				binarySearch(middle + 1, right, q);
			}
			return 1;
		}
		else if (A[middle] > q) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return -1;
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
		rightIdx = leftIdx = 0;
		int ans = binarySearch(0, N - 1, Q[i]);
		if (ans == -1)
			cout << "0 ";
		else
			cout << rightIdx-leftIdx+1 << ' ';
	}
	cout << '\n';
}