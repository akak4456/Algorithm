//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[500000];
int Q[500000];
int M;
int lowerbound(int start, int end, int q) {
	//cout << 'a';
	while (end > start) {
		int mid = (end + start) / 2;
		if (A[mid] >= q)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
}
int upperbound(int start, int end, int q) {
	while (end > start) {
		int mid = (end + start) / 2;
		if (A[mid] > q)
			end = mid;
		else
			start = mid + 1;
	}
	return end;
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
		int low = lowerbound(0, N - 1, Q[i]);
		int up = upperbound(0, N - 1, Q[i]);
		if (up == N - 1 && A[N - 1] == Q[i])
			up++;
		cout << up-low << ' ';
	}
	cout << '\n';
}