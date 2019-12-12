//result:맞았습니다!!
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	stack<int> st;
	vector<char> vec;
	int lastNum = 1;
	bool isCan = true;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (st.empty()||st.top() != t) {
			for (int j = lastNum; j <= t; j++) {
				st.push(j);
				vec.push_back('+');
			}
			lastNum = t + 1;
		}
		if (st.top() == t) {
			st.pop();
			vec.push_back('-');
		}
		else {
			isCan = false;
		}
	}
	if (isCan) {
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << '\n';
	}
	else {
		cout << "NO\n";
	}
}