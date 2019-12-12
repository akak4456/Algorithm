//result:맞았습니다!!
#include <iostream>
using namespace std;
int x, y;
int endDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> x >> y;
	int remainDay = 0;;
	for (int i = 0; i < x-1; i++) {
		remainDay += endDay[i];
	}
	remainDay += y;
	remainDay--;
	switch (remainDay % 7) {
	case 0:
		cout << "MON" << endl;
		break;
	case 1:
		cout << "TUE" << endl;
		break;
	case 2:
		cout << "WED" << endl;
		break;
	case 3:
		cout << "THU" << endl;
		break;
	case 4:
		cout << "FRI" << endl;
		break;
	case 5:
		cout << "SAT" << endl;
		break;
	case 6:
		cout << "SUN" << endl;
		break;
	}
}