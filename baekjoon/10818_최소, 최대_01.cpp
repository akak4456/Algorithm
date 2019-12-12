//result:맞았습니다!!
#include <iostream>
using namespace std;
int arr[1000000];
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int minV = 987654321;
	int maxV = -987654321;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > maxV) {
			maxV = arr[i];
		}
		if (arr[i] < minV) {
			minV = arr[i];
		}
	}
	cout << minV << ' ' << maxV << endl;
}