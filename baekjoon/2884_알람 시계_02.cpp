//result:맞았습니다!!
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int H, M;
	cin >> H >> M;
	if (M >= 45) {
		cout << H << ' ' << (M - 45) << endl;
	}
	else {
		if(H-1 >= 0)
		cout << (H - 1) << ' ' << (15 + M) << endl;
		else {
			cout << 23 << ' ' << (15 + M) << endl;
		}
	}
}