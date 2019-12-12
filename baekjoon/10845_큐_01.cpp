//result:맞았습니다!!
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	int q[100000];
	int front = 0;
	int back = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int X;
			cin >> X;
			q[back++] = X;
		}
		else if (command == "pop") {
			if (front == back) {
				cout << "-1\n";
			}
			else {
				cout << q[front++] << '\n';
			}
		}
		else if (command == "size") {
			cout << back - front << '\n';
		}
		else if (command == "empty") {
			if (front == back)
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (command == "front") {
			if (front == back)
				cout << "-1\n";
			else
				cout << q[front] << '\n';
		}
		else if (command == "back") {
			if (front == back)
				cout << "-1\n";
			else
				cout << q[back-1] << '\n';
		}
	}
}