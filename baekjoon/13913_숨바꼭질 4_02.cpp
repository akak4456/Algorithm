//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
int N, K;
bool visited[100001];
int parent[100001];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(parent, -1, sizeof(parent));
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
		//cout << x << endl;
		if (x == K) {
			cout << newCnt - 1 << '\n';
			break;
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			visited[x - 1] = true;
			parent[x - 1] = x;
			q.push(make_pair(x - 1, newCnt));
		}
		if (x + 1 <= 100000 && !visited[x + 1]) {
			visited[x + 1] = true;
			parent[x + 1] = x;
			q.push(make_pair(x + 1, newCnt));
		}
		if (2 * x <= 100000 && !visited[2 * x]) {
			visited[2 * x] = true;
			parent[2 * x] = x;
			q.push(make_pair(2 * x, newCnt));
		}
	}
	stack<int> route;
	route.push(K);
	int p = parent[K];
	while (p != -1) {
		route.push(p);
		p = parent[p];
	}
	while (!route.empty()) {
		cout << route.top() << ' ';
		route.pop();
	}
	cout << '\n';
}