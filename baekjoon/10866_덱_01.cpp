//result:맞았습니다!!
#include <iostream>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	int q[100000];
	int front = 50000, back = 50001;
	cin >> N;
	while (N--) {
		string command;
		cin >> command;
		if (command == "push_front") {
			int X;
			cin >> X;
			q[front--] = X;
		}
		else if (command == "push_back") {
			int X;
			cin >> X;
			q[back++] = X;
		}
		else if (command == "pop_front") {
			if (back-front == 1)
				cout << "-1\n";
			else {
				cout << q[front + 1] << '\n';
				front++;
			}
		}
		else if (command == "pop_back") {
			if (back-front == 1)
				cout << "-1\n";
			else {
				cout << q[back - 1] << '\n';
				back--;
			}
		}
		else if (command == "size") {
			cout << back - front - 1 << '\n';
		}
		else if (command == "empty") {
			if (back-front == 1)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (command == "front") {
			if (back-front == 1)
				cout << "-1\n";
			else
				cout << q[front + 1] << '\n';
		}
		else if (command == "back") {
			if (back-front == 1)
				cout << "-1\n";
			else
				cout << q[back - 1] << '\n';
		}
	}
}