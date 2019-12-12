//result:맞았습니다!!
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int P1 = 2000, P2 = 1000;
	while (N - P2 * 5 < 0) {
		P2--;
	}
	while (N - P1 * 3 - P2 * 5 < 0) {
		P1--;
	}
	while(true){
		if (P2 == 0 && N - P1 * 3 - P2 * 5 != 0) {
			cout << -1 << endl;
			break;
		}
		else if (N - P1 * 3 - P2 * 5 == 0) {
			cout << P1 + P2 << endl;
			break;
		}
		else {
			P2--;
			while (N - (P1+1) * 3 - P2 * 5 >= 0) {
				P1++;
			}
		}
	}
}