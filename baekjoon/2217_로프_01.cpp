//result:틀렸습니다
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int minVal = 987654321;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (t < minVal)
			minVal = t;
	}
	cout << minVal * N << '\n';
}