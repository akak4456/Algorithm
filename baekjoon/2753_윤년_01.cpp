//result:맞았습니다!!
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int year;
	cin >> year;
	if (year % 4 == 0) {
		if (year % 100 != 0 || year % 400 == 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	else {
		cout << 0 << endl;
	}
}