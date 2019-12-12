//result:런타임 에러
#include <iostream>
using namespace std;
int x, y;
bool isConstructor[10000];
void d(int n) {
	int sum = n;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	if (isConstructor[sum]) {
		isConstructor[sum] = false;
		d(sum);
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	for (int i = 1; i < 10000; i++) {
		isConstructor[i] = true;
	}
	for (int i = 1; i < 10000; i++) {
		if(isConstructor[i])
			d(i);
	}
	for (int i = 1; i < 10000; i++) {
		if (isConstructor[i])
			cout << i << '\n';
	}
}