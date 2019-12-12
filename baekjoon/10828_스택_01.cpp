//result:맞았습니다!!
#include <iostream>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	string command;
	cin >> N;
	int st[100000];
	int sz = 0;
	int sp = 0;
	while (N--) {
		cin >> command;
		int X;
		if (command == "push") {
			cin >> X;
			st[sp++] = X;
			sz++;
		}
		else if (command == "pop") {
			if (sz == 0)
				cout << "-1\n";
			else {
				cout << st[sp - 1] << '\n';
				sp--;
				sz--;
			}
		}
		else if (command == "size") {
			cout << sz << '\n';
		}
		else if (command == "empty") {
			if (sz > 0)
				cout << "0" << '\n';
			else
				cout << "1\n";
		}
		else if (command == "top") {
			if (sz == 0) {
				cout << "-1\n";
			}
			else {
				cout << st[sp - 1] << '\n';
			}
		}
	}
}