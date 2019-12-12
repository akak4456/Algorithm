//result:맞았습니다!!
#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int A, B, V;
	cin >> A >> B >> V;
	if((V-A)%(A-B) == 0)
		cout << (V - A) / (A - B) + 1 << '\n';
	else
		cout << (V - A) / (A - B) + 2 << '\n';
}