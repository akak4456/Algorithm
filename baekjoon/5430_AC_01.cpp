//result:맞았습니다!!
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <string>
#include <cstring>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--) {
		bool reversed = false;
		bool isCan = true;
		string func;
		cin >> func;
		int n;
		cin >> n;
		deque<int> dq;
		char arr[400005];
		cin >> arr;
		char* tmp = strtok(arr, "[,]");
		while (tmp) {
			dq.push_back(stoi(tmp));
			tmp = strtok(NULL, "[,]");
		}
		for (int i = 0; i < func.size(); i++) {
			if (func[i] == 'R') {
				reversed = !reversed;
			}
			else if (func[i] == 'D') {
				if (dq.empty()) {
					isCan = false;
					break;
				}
				if (!reversed) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (!isCan) {
			cout << "error\n";
		}
		else {
			if (!reversed) {
				cout << '[';
				while (dq.size() > 1) {
					cout << dq.front() << ',';
					dq.pop_front();
				}
				if(!dq.empty())
				cout << dq.front();
				cout << "]\n";
			}
			else {
				cout << '[';
				while (dq.size() > 1) {
					cout << dq.back() << ',';
					dq.pop_back();
				}
				if (!dq.empty())
				cout << dq.back();
				cout << "]\n";
			}
		}
	}
}