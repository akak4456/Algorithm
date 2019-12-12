//result:정답
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_DISCS = 12;
int get(int state, int index) {
	return (state >> (index * 2)) & 3;
}
int set(int state, int index, int value) {
	return (state & ~(3 << (index * 2))) | (value << (index * 2));
}
int c[1 << (MAX_DISCS * 2)];
int sgn(int x) { if (!x) return 0; return x > 0 ? 1 : -1; }
int incr(int x) { if (x < 0) return x - 1; return x + 1; }
int bidir(int discs, int begin, int end) {
	if (begin == end) return 0;
	queue<int> q;
	for (int i = 0; i < (1 << (MAX_DISCS * 2)); i++)
		c[i] = 0;
	q.push(begin); c[begin] = 1;
	q.push(end); c[end] = -1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		int top[4] = { -1,-1,-1,-1 };
		for (int i = discs - 1; i >= 0; i--)
			top[get(here, i)] = i;
		for (int i = 0; i < 4; i++) {
			if (top[i] == -1) continue;
			for (int j = 0; j < 4; j++) {
				if (i != j && (top[j] == -1 || top[j] > top[i])) {
					int there = set(here, top[i], j);
					if (c[there] == 0) {
						c[there] = incr(c[here]);
						q.push(there);
					}
					else if (sgn(c[there]) != sgn(c[here]))
						return abs(c[there]) + abs(c[here]) - 1;
				}
			}
		}
	}
	return -1;
}
int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		int n;
		cin >> n;
		int begin = 0;
		for (int i = 0; i < 4; i++) {
			int cnt;
			cin >> cnt;
			while (cnt--) {
				int t;
				cin >> t;
				begin = set(begin, t-1, i);
			}
		}
		int end = 0;
		for (int i = 0; i < n; i++) {
			end = set(end, i, 3);
		}
		cout << bidir(n, begin, end) << endl;
	}
}