//result:맞았습니다!!
#include <iostream>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
		if (N % 2 == 1) {
			for (int line = 1; line <= N; line++) {
					for (int k = 1; k <= N / 2 + 1; k++) {
						cout << "* ";
					}
					cout << "\n";
					for (int k = 1; k <= N / 2; k++) {
						cout << " *";
					}
					cout << "\n";
			}
			
		}
		else {
			for (int line = 1; line <= N; line++) {
					for (int k = 1; k <= N / 2; k++) {
						cout << "* ";
					}
					cout << "\n";
					for (int k = 1; k <= N / 2; k++) {
						cout << " *";
					}
					cout << "\n";
			}
		}
}