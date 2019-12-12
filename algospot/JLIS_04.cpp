//result:정답
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const long long NEGINF = numeric_limits<long long>::min();
int C, N,M;
int arr1[100];
int arr2[100];
int cache[101][101];
int lis(int start1,int start2) {
	int& ret = cache[start1+1][start2+1];
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	long long a = (start1== -1 ? NEGINF : arr1[start1]);
	long long b = (start2 == -1 ? NEGINF : arr2[start2]);
	long long maxElement = max(a, b);
	for (int next1 = start1 + 1; next1 < N; next1++) {
		if (maxElement < arr1[next1]) {
			ret = max(ret, lis(next1, start2) + 1);
		}
	}
	for (int next2 = start2 + 1; next2 < M; next2++) {
		if (maxElement < arr2[next2]) {
			ret = max(ret, lis(start1, next2) + 1);
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		memset(cache, -1, sizeof(cache));
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> arr1[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> arr2[i];
		}
		cout << lis(-1,-1) << '\n';
	}
}