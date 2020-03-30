//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
const int MOD = 1000000009;
const int MAX_N = 1000000;
long long int D[MAX_N+1];
int T,N;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	D[0] = 1;
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for (int i = 4; i <= MAX_N; i++) {
		D[i] = (D[i - 1] % MOD + D[i - 2] %MOD + D[i - 3] %MOD)%MOD;
	}
	cin >> T;
	while (T--) {
		cin >> N;
		cout << D[N] << '\n';
	}
}