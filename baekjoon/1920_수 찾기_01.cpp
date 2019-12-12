//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[100000];
int Q[100000];
int M;
bool binarySearch(int start, int end, int q) {
	int left = start;
	int right = end;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (A[middle] == q) {
			return true;
		}
		else if (A[middle] > q) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return false;
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
		if (binarySearch(0, N - 1, Q[i])) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
}