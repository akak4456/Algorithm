//result:틀렸습니다
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
		cout << (H - 1) << ' ' << (15 + M) << endl;
	}
}