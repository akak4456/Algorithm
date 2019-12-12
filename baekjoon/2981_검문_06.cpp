//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[100];
int gcd(int a, int b) {
	//cout << a << ' ' << b << endl;
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	sort(num, num + N);
	int a = num[1] - num[0];
	for (int i = 2; i < N; i++) {
		a = gcd(a, num[i] - num[i - 1]);
	}
	vector<int> printArr;
	for (int M = 2; M*M <= a; M++) {
		if (a % M == 0) {
			printArr.push_back(M);
			if (M * M < a)
				printArr.push_back(a / M);
		}
	}
	printArr.push_back(a);
	sort(printArr.begin(), printArr.end());
	for (int i = 0; i < printArr.size(); i++)
		cout << printArr[i] << ' ';
	cout << endl;
}