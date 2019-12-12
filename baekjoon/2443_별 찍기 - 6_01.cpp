//result:맞았습니다!!
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = N; i >= 1; i--) {
		int line = N - i;
		for (int j = 1; j <= line; j++) {
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++) {
			cout << "*";
		}
		cout << '\n';
	}
}