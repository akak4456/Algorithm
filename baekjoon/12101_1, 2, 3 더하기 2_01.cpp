//result:틀렸습니다
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int D[11];
int N, K;
vector<int> result;
bool solve(int n,int k) {
	//cout << n << ' ' << k << endl;
	for (int i = 1; i <= 3; i++) {
		//cout << "D:" << D[n - 1] << endl;
		if (D[n - i] >= k) {
			result.push_back(i);
			solve(n - i, k);
			return true;
		}
		k -= D[n - i];
		if (k <= 0)
			return false;
	}
	return false;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	D[0] = 1;
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for (int i = 4; i <= 10; i++) {
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}
	if (solve(N, K)) {
		for (int i = 0; i < result.size() - 1; i++) {
			cout << result[i] << '+';
		}
		cout << result.back() << '\n';
	}
	else {
		cout << "-1\n";
	}
}