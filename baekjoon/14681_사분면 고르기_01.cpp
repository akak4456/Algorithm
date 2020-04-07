//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y;
	cin >> x >> y;
	if (x > 0) {
		if (y > 0)
			cout << "1\n";
		else
			cout << "4\n";
	}
	else {
		if (y > 0)
			cout << "2\n";
		else
			cout << "3\n";
	}
}