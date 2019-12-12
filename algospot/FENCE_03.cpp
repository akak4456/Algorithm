//result:시간초과
#include <iostream>
using namespace std;
const int MAX_HEIGHT = 20000;
int C;
int N;
int H[20001];
int fence(int MIN, int MAX) {
	if (MIN == MAX) {
		return H[MIN];
	}
	int half = (MIN + MAX) / 2;
	int left = fence(MIN, half);
	int right = fence(half + 1, MAX);
	int halfLeftIdx = half;
	int halfRightIdx = half + 1;
	int h;
	bool direction;
	//true 왼쪽으로 false 오른쪽으로
	if (H[halfLeftIdx] > H[halfRightIdx]) {
		h = H[halfRightIdx];
		direction = true;
	}
	else {
		h = H[halfLeftIdx];
		direction = false;
	}
	int cross = -1;
	while (halfRightIdx != N && halfLeftIdx != 1) {
		while (halfRightIdx < N&&h <= H[halfRightIdx+1]) {
			halfRightIdx++;
		}
		while (halfLeftIdx > 1&&h <= H[halfLeftIdx - 1]) {
			halfLeftIdx--;
		}
		int area = h*(halfRightIdx - halfLeftIdx + 1);
		if (cross < area) {
			cross = area;
		}
		if (direction) {
			if (halfLeftIdx == 1) {
				h = H[halfRightIdx + 1];
				halfRightIdx++;
			}
			else {
				h = H[halfLeftIdx - 1];
				halfLeftIdx--;
			}
		}
		else {
			if (halfRightIdx == N) {
				h = H[halfLeftIdx - 1];
				halfLeftIdx--;
			}
			else {
				h = H[halfRightIdx + 1];
				halfRightIdx++;
			}
		}
		direction != direction;
	}
	int ret = -1;
	if (ret < left) {
		ret = left;
	}
	if (ret < right) {
		ret = right;
	}
	if (ret < cross) {
		ret = cross;
	}
	return ret;
}
int main() {
	cin >> C;
	for (int i = 1; i <= C; i++) {
		cin >> N;
		for (int j = 1; j <= N; j++) {
			int t;
			cin >> t;
			H[j] = t;
		}
		cout << fence(1, N) << endl;
	}
}