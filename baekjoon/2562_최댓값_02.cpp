//result:맞았습니다!!
#include <iostream>
using namespace std;
int arr[9];
int main() {
	std::ios::sync_with_stdio(false);
	int idx = -1;
	int maxV = -987654321;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (arr[i] > maxV) {
			maxV = arr[i];
			idx = i + 1;
		}
	}
	cout << maxV << endl << idx << endl;
}