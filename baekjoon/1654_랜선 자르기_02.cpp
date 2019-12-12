//result:틀렸습니다
#include <iostream>
#include <algorithm>
using namespace std;
int K, N;
long long int A[10000];
int binarysearch() {
	long long int left = 0;
	long long int right = A[0];
	long long int mid;
	while (right - left > 1) {
		
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
	int cnt = 0;
	for (int i = 0; i < K; i++)
		cnt += A[i] / right;
	if (cnt >= N)
		return right;
	return left;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> A[i];
	sort(A, A + K);
	cout << binarysearch()<< '\n';
}