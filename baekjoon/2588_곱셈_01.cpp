//result:맞았습니다!!
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	int q = b;
	int r = q % 10;
	cout << a * r << endl;
	q = (q / 10) * 10;
	r = q % 100;
	cout << (a * r)/10 << endl;
	q = (q / 100) * 100;
	r = q;
	cout << (a * r)/100 << endl;
	cout << a * b << endl;
}