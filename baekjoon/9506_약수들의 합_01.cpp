//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
const int MOD = 45678;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while (cin >> n) {
		if (n == -1)
			break;
		int sum = 0;
		vector<int> measure;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
				measure.push_back(i);
			}
		}
		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < measure.size() - 1; i++)
				cout << measure[i] << " + ";
			cout << measure.back();
			cout << '\n';
		}
		else {
			cout << n << " is NOT perfect.\n";
		}
	}
}