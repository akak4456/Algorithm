//result:정답
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>,greater<int> > input;
int c, n;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			input.push(t);
		}
		int cost = 0;
		while (input.size() > 1) {
			int first = input.top();
			input.pop();
			int second = input.top();
			input.pop();
			//cout << first << " " << second << endl;
			cost += first + second;
			input.push(first + second);
		}
		input.pop();
		cout << cost << endl;
	}
}