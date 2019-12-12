//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;
bool maze[100][100];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '1') {
				maze[i][j] = true;
			}
			else {
				maze[i][j] = false;
			}
		}
	}
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 0), 1));
	maze[0][0] = false;
	while (!q.empty()) {
		pair<pair<int, int>, int> tmp = q.front();
		q.pop();
		int ny = tmp.first.first, nx = tmp.first.second;
		int newCnt = tmp.second + 1;
		if (ny == N - 1 && nx == M - 1) {
			cout << newCnt - 1 << '\n';
			break;
		}
		if (ny - 1 >= 0 && maze[ny - 1][nx]) {
			maze[ny - 1][nx] = false;
			q.push(make_pair(make_pair(ny - 1, nx), newCnt));
		}
		if (ny + 1 < N && maze[ny + 1][nx]) {
			maze[ny + 1][nx] = false;
			q.push(make_pair(make_pair(ny + 1, nx), newCnt));
		}
		if (nx - 1 >= 0 && maze[ny][nx - 1]) {
			maze[ny][nx - 1] = false;
			q.push(make_pair(make_pair(ny, nx - 1), newCnt));
		}
		if (nx + 1 < M && maze[ny][nx + 1]) {
			maze[ny][nx + 1] = false;
			q.push(make_pair(make_pair(ny, nx + 1), newCnt));
		}
	}
}