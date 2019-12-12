//result:맞았습니다!!
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	stack<char> st;
	for (int i = 0; i < T; i++) {
		string t;
		cin >> t;
		bool isCan = true;
		for (int j = 0; j < t.size(); j++) {
			if (t[j] == '(') {
				st.push(t[j]);
			}
			else {
				if (st.empty()) {
					isCan = false;
					break;
				}
				st.pop();
			}
		}
		if (isCan&&st.empty()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		while (!st.empty())
			st.pop();
	}
}