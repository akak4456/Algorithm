//result:시간초과
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int C, N,M;
int arr1[100];
int arr2[100];
int cache[100][100];
int lis(int start1,int start2) {
	int& ret = cache[start1][start2];
	if (ret != -1) {
		return ret;
	}
	ret = 2;
	if (arr1[start1] > arr2[start2]) {
		for (int next1 = start1 + 1; next1 < N; next1++) {
			if (arr1[start1] < arr1[next1]) {
				ret = max(ret, lis(next1, start2) + 1);
			}
		}
	}
	else {
		for (int next2 = start2 + 1; next2 < M; next2++) {
			if (arr2[start2] < arr2[next2]) {
				ret = max(ret, lis(start1, next2) + 1);
			}
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
		for (int i = 1; i <= N; i++) {
			cin >> arr1[i];
		}
		for (int i = 1; i <= M; i++) {
			cin >> arr2[i];
		}
		int ans = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				ans = max(ans, lis(i, j));
			}
		}
		cout << ans << '\n';
	}
}