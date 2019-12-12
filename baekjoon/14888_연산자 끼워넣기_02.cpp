//result:맞았습니다!!
#include <iostream>
using namespace std;
int A[11];
char op[10];
int N;
int maxValue = -1000000001;
int minValue = 1000000001;
bool used[10];
void solve(int value,int next) {
	if (next == N) {
		//cout << value << '\n';
		if (value > maxValue) {
			maxValue = value;
		}
		if (value < minValue) {
			minValue = value;
		}
		return;
	}
	for (int i = 0; i < N-1; i++) {
		if (used[i] == false) {
			used[i] = true;
			int newValue = value;
			int newNext = next + 1;
			if (op[i] == '+') {
				newValue = newValue + A[next];
			}else if (op[i] == '-') {
				newValue = newValue - A[next];
			}else if (op[i] == '*') {
				newValue = newValue * A[next];
			}else if (op[i] == '/') {
				newValue = newValue / A[next];
			}
			solve(newValue, newNext);
			used[i] = false;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	int idx = 0;
	for (int i = 0; i < 4; i++) {
		int t;
		cin >> t;
		while (t > 0) {
			if (i == 0) {
				op[idx++] = '+';
			}else if (i == 1) {
				op[idx++] = '-';
			}else if (i == 2) {
				op[idx++] = '*';
			}else if (i == 3) {
				op[idx++] = '/';
			}
			t--;
		}
	}
	for (int i = 0; i < 10; i++)
		used[i] = false;
	solve(A[0],1);
	cout << maxValue << '\n' << minValue << '\n';
}