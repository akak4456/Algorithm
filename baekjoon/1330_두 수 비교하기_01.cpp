//result:맞았습니다!!
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if (a < b)
		cout << "<" << endl;
	else if (a > b)
		cout << ">" << endl;
	else
		cout << "==" << endl;
}