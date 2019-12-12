//result:틀렸습니다
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, K;
bool visited[100000];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	queue<pair<int, int> > q;
	q.push(make_pair(N, 0));
	visited[N] = true;
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		int x = tmp.first;
		int newCnt = tmp.second + 1;
		visited[x] = true;
		if (x == K) {
			cout << newCnt - 1 << '\n';
			break;
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			visited[x - 1] = true;
			q.push(make_pair(x - 1, newCnt));
		}
		if (x + 1 <= 100000 && !visited[x + 1]) {
			visited[x + 1] = true;
			q.push(make_pair(x + 1, newCnt));
		}
		if (2*x <= 100000 && !visited[2*x]) {
			visited[2 * x] = true;
			q.push(make_pair(2*x, newCnt));
		}
	}
}