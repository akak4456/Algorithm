//result:런타임 오류
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
vector<int> input;
vector<int> sorted;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int N;
		cin >> N;
		input.resize(N);
		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}
		sorted = input;
		sort(sorted.begin(), sorted.end());
		queue<pair<int, vector<int> > >q;
		q.push(make_pair(0, input));
		while (!q.empty()) {
			vector<int> fr = q.front().second;
			int cnt = q.front().first;
			q.pop();
			bool isCan = true;
			for (int i = 0; i < N; i++) {
				if (sorted[i] != fr[i]) {
					isCan = false;
					break;
				}
			}
			if (isCan) {
				cout << cnt << '\n';
				break;
			}
			for (int i = 0; i < N; i++) {
				for (int j = i + 1; j < N; j++) {
					vector<int> newVec = fr;
					reverse(newVec.begin() + i, newVec.begin() + j + 1);
					q.push(make_pair(cnt + 1, newVec));
				}
			}
		}
	}
}