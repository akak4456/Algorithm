//result:시간 초과
#include <iostream>
#include <algorithm>
using namespace std;
int K, N;
long long int A[10000];
int binarysearch() {
	long long int left = 0;
	long long int right = A[0];
	long long int mid;
	while (left < right) {
		mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += A[i] / mid;
		if (cnt < N) {
			right = mid-1;
		}
		else {
			left = mid;
		}
	}
	return left;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> A[i];
	sort(A, A + K);
	cout << binarysearch() << endl;
}