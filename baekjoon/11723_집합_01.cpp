//result:맞았습니다!!
#include <iostream>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned int S = (1 << 20);
	unsigned int M;
	cin >> M;
	while (M--) {
		string order;
		unsigned int x;
		cin >> order;
		if (order == "add") {
			cin >> x;
			S |= (1 << (x-1));
		}
		else if (order == "remove") {
			cin >> x;
			S &= ~(1 << (x-1));
		}
		else if (order == "check") {
			cin >> x;
			if ((S & (1 << (x-1))) == 0) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if (order == "toggle") {
			cin >> x;
			S ^= (1 << (x-1));
		}
		else if (order == "all") {
			S = (1 << 20);
			S--;
			//cout << S;
		}
		else if (order == "empty") {
			S = (1 << 20);
		}
	}
}