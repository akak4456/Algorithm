//result:오답
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int C, N;
int arr[500];
int cache[500];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cache[0] = 1;
		for (int i = 1; i < N; i++) {
			cache[i] = 1;
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j]) {
					cache[i] = max(cache[i], cache[j] + 1);
				}
			}
		}
		cout << cache[N - 1] << '\n';
	}
}