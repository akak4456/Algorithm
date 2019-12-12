//result:오답
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
	if (H[halfLeftIdx] > H[halfRightIdx]) {
		h = H[halfRightIdx];
	}
	else {
		h = H[halfLeftIdx];
	}
	int cross = -1;
	while (halfRightIdx != MAX && halfLeftIdx != MIN) {
		while (halfRightIdx < MAX&&h <= H[halfRightIdx + 1]) {
			halfRightIdx++;
		}
		while (halfLeftIdx > MIN&&h <= H[halfLeftIdx - 1]) {
			halfLeftIdx--;
		}
		int area = h * (halfRightIdx - halfLeftIdx + 1);
		if (cross < area) {
			cross = area;
		}
		if (halfRightIdx == MAX) {
			h = H[halfLeftIdx - 1];
			halfLeftIdx--;
		}
		else if (halfLeftIdx == MIN) {
			h = H[halfRightIdx + 1];
			halfRightIdx++;
		}
		else  if (H[halfLeftIdx - 1] > H[halfRightIdx + 1]) {
			h = H[halfLeftIdx - 1];
			halfLeftIdx--;
		}
		else {
			h = H[halfRightIdx + 1];
			halfRightIdx++;
		}
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