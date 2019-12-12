//result:정답
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int C;
string ans;
stack<char> st;
bool canDo() {
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == '(' || ans[i] == '{' || ans[i] == '[') {
			st.push(ans[i]);
		}
		else {
			if (st.empty())
				return false;
			if (ans[i] == ')') {
				if (st.top() == '(')
					st.pop();
				else
					return false;
			}
			else if (ans[i] == '}') {
				if (st.top() == '{')
					st.pop();
				else
					return false;
			}
			else if (ans[i] == ']') {
				if (st.top() == '[')
					st.pop();
				else
					return false;
			}
		}
	}
	return st.empty();
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		while (!st.empty()) {
			st.pop();
		}
		cin >> ans;
		if (canDo()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}