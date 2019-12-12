//result:맞았습니다!!
#include <iostream>
using namespace std;

int main() {
	while (true) {
		int t1, t2;
		cin >> t1 >> t2;
		if (t1 == 0 && t2 == 0)
			break;
		if (t2 % t1 == 0) {
			cout << "factor\n";
		}
		else if (t1 % t2 == 0) {
			cout << "multiple\n";
		}
		else {
			cout << "neither\n";
		}
	}
}