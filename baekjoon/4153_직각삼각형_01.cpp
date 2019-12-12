//result:틀렸습니다
#include <iostream>
#include <cmath>
using namespace std;
int cnt[1001];
int cnt2[1001];
int main() {
	std::ios::sync_with_stdio(false);
	while(true){
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a * a + b * b == c * c)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
}