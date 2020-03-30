//result:정답
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	bool visited[1000001];
	memset(visited, 0, sizeof(visited));
	queue<pair<int,int> > q;
	q.push(make_pair(S,0));
	bool canDo = false;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		visited[p.first] = true;
		q.pop();
		if (p.first == G) {
			canDo = true;
			cout << p.second << '\n';
			break;
		}
		if (p.first + U <= F && !visited[p.first + U]) {
			visited[p.first + U] = true;
			q.push(make_pair(p.first + U, p.second + 1));
		}
		if (p.first - D >= 1 && !visited[p.first - D]) {
			visited[p.first - D] = true;
			q.push(make_pair(p.first - D, p.second + 1));
		}
	}
	if (!canDo)
		cout << "use the stairs\n";
}