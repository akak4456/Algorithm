//result:맞았습니다!!
#include <iostream>
#include <string>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int a, b, c;
	cin >> a >> b >> c;
	if (c - b <= 0) {
		cout << -1 << '\n';
	}
	else {
		cout << (a / (c - b)) + 1 << '\n';
	}
}