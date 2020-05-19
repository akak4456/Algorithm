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
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string N;
	int F;
	cin >> N >> F;
	string head = N.substr(0, N.size()-2);
	for (int i = 0; i <= 99; i++) {
		string tail = to_string(i);
		if (tail.size() == 1)
			tail = "0" + tail;
		string newNum = head + tail;
		if (stoi(newNum) % F == 0) {
			cout << tail << '\n';
			break;
		}
	}
}