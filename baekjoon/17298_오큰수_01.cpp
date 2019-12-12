//result:맞았습니다!!
#include <iostream>
#include <stack>
using namespace std;
int A[1000000];
int result[1000000];
int N;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	stack<int> st;
	for (int i = N - 1; i >= 0; i--) {
		if (st.empty()) {
			result[i] = -1;
		}
		else {
			while (!st.empty()&&A[i] >= st.top()) {
				st.pop();
			}
			if (st.empty())
				result[i] = -1;
			else
				result[i] = st.top();
		}
		st.push(A[i]);
	}
	for (int i = 0; i < N; i++)
		cout << result[i] << ' ';
}