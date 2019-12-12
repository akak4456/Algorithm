//result:맞았습니다!!
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - i; j++) {
			cout << " ";
		}
		cout << "*";
		if (i >= 2) {
			for (int j = 1; j <= 2 * (i - 1) - 1; j++)
				cout << " ";
			cout << "*";
		}
		cout << '\n';
	}
}