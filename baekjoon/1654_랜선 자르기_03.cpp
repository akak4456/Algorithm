//result:맞았습니다!!
/*
전에 틀린 이유
최소 길이 랜선이 무조건 포함되어야 한다고 생각해서
*/
#include <iostream>
#include <algorithm>
using namespace std;
int K, N;
long long int A[10000];
int binarysearch() {
	long long int left = 0;
	long long int right = 1;
	for (int i = 1; i <= 31; i++) {
		right *= 2;
	}
	long long int mid;
	while (right - left > 1) {
		//cout << right << ' ' << left << endl;
		mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++)
			cnt += A[i] / mid;
		if (cnt < N) {
			right = mid - 1;
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
	cout << binarysearch() << '\n';
}