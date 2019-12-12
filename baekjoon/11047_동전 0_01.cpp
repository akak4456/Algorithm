//result:맞았습니다!!
#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	vector<int> coin;
	coin.resize(N);
	for (int i = 0; i < N; i++)
		cin >> coin[i];
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		cnt += K / coin[i];
		K -= (K / coin[i]) * coin[i];
	}
	cout << cnt << '\n';
}