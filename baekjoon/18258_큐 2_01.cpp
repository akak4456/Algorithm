//result:맞았습니다!!
#include <iostream>
using namespace std;

int N;
int q[3000000];
int front, back;
int sz;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while (N--) {
		string command;
		cin >> command;
		if (command == "push") {
			cin >> q[back++];
			sz++;
		}
		else if (command == "pop") {
			if (sz == 0) {
				cout << "-1\n";
			}
			else {
				cout << q[front++] << '\n';
				sz--;
			}
		}
		else if (command == "size") {
			cout << sz << '\n';
		}
		else if (command == "empty") {
			if (sz == 0) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (command == "front") {
			if (sz == 0) {
				cout << "-1\n";
			}
			else {
				cout << q[front] << '\n';
			}
		}
		else if (command == "back") {
			if (sz == 0) {
				cout << "-1\n";
			}
			else {
				cout << q[back-1] << '\n';
			}
		}
	}
}