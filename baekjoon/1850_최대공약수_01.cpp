//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
long long int gcd(long long int A, long long int B) {
	//cout << A << ' ' << B << endl;
	if (A < B) {
		long long int tmp = A;
		A = B;
		B = tmp;
	}
	if (A % B == 0)
		return B;
	return gcd(B, A % B);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int A, B;
	cin >> A >> B;
	for (int i = 0; i < gcd(A, B); i++)
		cout << "1";
	cout  << '\n';
}