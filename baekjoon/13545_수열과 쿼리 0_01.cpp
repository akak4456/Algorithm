//result:틀렸습니다
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100001];
int oneCnt[100001];
int minusOneCnt[100001];
int M;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		oneCnt[i] = oneCnt[i - 1];
		minusOneCnt[i] = minusOneCnt[i - 1];
		if (A[i] == 1)
			oneCnt[i]++;
		else
			minusOneCnt[i]++;
	}
	cin >> M;
	while (M--) {
		int from, to;
		cin >> from >> to;
		cout << min(oneCnt[to] - oneCnt[from - 1], minusOneCnt[to] - minusOneCnt[from - 1]) * 2 << '\n';
	}
}