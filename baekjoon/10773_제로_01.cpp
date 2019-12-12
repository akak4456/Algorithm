//result:맞았습니다!!
#include <iostream>
#include <stack>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int K;
	cin >> K;
	stack<int> st;
	for (int i = 0; i < K; i++) {
		int t;
		cin >> t;
		if (t == 0)
			st.pop();
		else
			st.push(t);
	}
	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum << '\n';
}