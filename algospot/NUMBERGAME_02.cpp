//result:정답
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 987654321;
int n;
int arr[50];
int cache[50][50];
int play(int left, int right) {
	if (left > right) return 0;
	int& ret = cache[left][right];
	if (ret != -INF) return ret;

	ret = max(arr[left] - play(left + 1, right),arr[right]-play(left,right-1));

	if (right - left >= 1) {
		ret = max(ret, -play(left + 2, right));
		ret = max(ret, -play(left , right-2));
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		for (int i = 0;i < 50;i++) {
			for (int j = 0;j < 50;j++) {
				for (int k = 0;k < 2;k++) {
					cache[i][j] = -INF;
				}
			}
		}
		cin >> n;
		for (int i = 0;i < n;i++)
			cin >> arr[i];
		cout << play(0,n-1) << '\n';
	}
}