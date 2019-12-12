//result:맞았습니다!!
#include <iostream>
using namespace std;

int cnt[10001];
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	while (N--) {
		int t;
		cin >> t;
		cnt[t]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < cnt[i]; j++)
			cout << i << '\n';
	}
}