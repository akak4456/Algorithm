//result:맞았습니다!!
#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int main() {
	std::ios::sync_with_stdio(false);
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		arr[i] %= 42;
	}
	sort(arr, arr + 10);
	int idx = -1;
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		if (idx != arr[i]) {
			idx = arr[i];
			cnt++;
		}
	}
	cout << cnt << endl;
}