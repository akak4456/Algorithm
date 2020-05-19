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
int rev(string x) {
	string newX = "";
	for (int i = 0; i < x.size(); i++) {
		newX = x[i]+newX;
	}
	return stoi(newX);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string X, Y;
	cin >> X >> Y;
	cout << rev(to_string(rev(X) + rev(Y))) << '\n';
}