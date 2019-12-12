//result:오답
#include <iostream>
using namespace std;
int C;
int N;
int arr[8];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		int cnt = 0;
		while (true) {
			bool isBreak = true;
			for (int i = 1; i < N; i++) {
				if (arr[i - 1] > arr[i]) {
					isBreak = false;
					int startIdx = i-1;
					int endIdx = i;
					while (endIdx < N&& arr[startIdx] > arr[endIdx]) {
						endIdx++;
					}
					endIdx--;
					int tmp[8];
					for (int j = startIdx; j <= endIdx; j++) {
						tmp[j] = arr[j];
					}
					for (int j = startIdx; j <= endIdx; j++) {
						arr[j] = tmp[endIdx - (j-startIdx)];
					}
					//cout << startIdx << ' ' << endIdx << endl;
					break;
				}
			}
			//break;
			for (int i = 0; i < N; i++) {
				//cout << arr[i] << ' ';
			}
			//cout << endl;
			if (isBreak)
				break;
			cnt++;
		}
		cout << cnt << endl;
	}
}