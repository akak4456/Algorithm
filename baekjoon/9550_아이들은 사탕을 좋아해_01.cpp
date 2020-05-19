//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			int t;
			cin >> t;
			sum += t / K;
		}
		cout << sum << '\n';
	}
}