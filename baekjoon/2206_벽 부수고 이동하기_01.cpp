//result:틀렸습니다
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
struct Point {
	int x, y;
	int cnt;
	int breakCnt;
};
int maze[1000][1000];
int main() {
	std::ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			maze[i][j] = str[j] - '0';
		}
	}
	queue<Point> q;
	Point tmp;
	tmp.x = 0;
	tmp.y = 0;
	tmp.cnt = 0;
	tmp.breakCnt = 0;
	q.push(tmp);
	bool isCan = false;
	while (!q.empty()) {
		Point tmp = q.front();
		q.pop();
		int nx = tmp.x, ny = tmp.y;
		int newCnt = tmp.cnt;
		int newBreakCnt = tmp.breakCnt;
		if (nx == M - 1 && ny == N - 1) {
			isCan = true;
			cout << newCnt + 1 << '\n';
			break;
		}
		maze[ny][nx] = 2;
		if (ny - 1 >= 0) {
			Point tmp2;
			tmp2.x = nx;
			tmp2.y = ny - 1;
			tmp2.cnt = newCnt + 1;
			if (maze[ny - 1][nx] == 0) {
				tmp2.breakCnt = newBreakCnt;
				q.push(tmp2);
				maze[ny - 1][nx] = 2;
			}
			else if (maze[ny - 1][nx] == 1&&newBreakCnt == 0) {
				tmp2.breakCnt = newBreakCnt + 1;
				q.push(tmp2);
				maze[ny - 1][nx] = 2;
			}
		}
		if (ny + 1 < N) {
			Point tmp2;
			tmp2.x = nx;
			tmp2.y = ny + 1;
			tmp2.cnt = newCnt + 1;
			if (maze[ny + 1][nx] == 0) {
				tmp2.breakCnt = newBreakCnt;
				q.push(tmp2);
				maze[ny + 1][nx] = 2;
			}
			else if (maze[ny + 1][nx] == 1 && newBreakCnt == 0) {
				tmp2.breakCnt = newBreakCnt + 1;
				q.push(tmp2);
				maze[ny + 1][nx] = 2;
			}
		}
		if (nx - 1 >= 0) {
			Point tmp2;
			tmp2.x = nx - 1;
			tmp2.y = ny;
			tmp2.cnt = newCnt + 1;
			if (maze[ny][nx - 1] == 0) {
				tmp2.breakCnt = newBreakCnt;
				q.push(tmp2);
				maze[ny][nx - 1] = 2;
			}
			else if (maze[ny][nx - 1] == 1 && newBreakCnt == 0) {
				tmp2.breakCnt = newBreakCnt + 1;
				q.push(tmp2);
				maze[ny][nx - 1] = 2;
			}
		}
		if (nx + 1 < M) {
			Point tmp2;
			tmp2.x = nx + 1;
			tmp2.y = ny;
			tmp2.cnt = newCnt + 1;
			if (maze[ny][nx + 1] == 0) {
				tmp2.breakCnt = newBreakCnt;
				q.push(tmp2);
				maze[ny][nx + 1] = 2;
			}
			else if (maze[ny][nx + 1] == 1 && newBreakCnt == 0) {
				tmp2.breakCnt = newBreakCnt + 1;
				q.push(tmp2);
				maze[ny][nx + 1] = 2;
			}
		}
	}
	if (!isCan) {
		cout << "-1\n";
	}
}