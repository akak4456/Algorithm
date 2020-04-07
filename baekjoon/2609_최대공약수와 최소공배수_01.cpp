//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int A, B;
int gcd(int A, int B) {
	if (A % B == 0)
		return B;
	if (A < B) {
		int tmp = A;
		A = B;
		B = tmp;
	}
	return gcd(B, A % B);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;
	cout << gcd(A, B) << '\n';
	cout << (A * B) / gcd(A, B) << '\n';
}