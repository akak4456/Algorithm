//result:맞았습니다!!
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int N, M;
		cin >> N >> M;
		queue<int> q;
		for (int i = 0; i < N; i++) {
			q.push(i);
		}
		int rank[100];
		for (int i = 0; i < N; i++)
			cin >> rank[i];
		int order[100];
		int cnt = 1;
		while (!q.empty()) {
			int t = q.front();
			q.pop();
			bool isCan = true;
			for (int i = 0; i < N; i++) {
				if (t == i||rank[i] == -1)
					continue;
				if (rank[i] > rank[t]) {
					isCan = false;
					break;
				}
			}
			if (isCan) {
				order[t] = cnt++;
				rank[t] = -1;
			}
			else {
				q.push(t);
			}
		}
		cout << order[M] << '\n';
	}
}