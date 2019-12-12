//result:맞았습니다!!
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
int maze[1000][1000];
int dist[1000][1000][2];
const int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
struct Point {
	int x, y, w;
};
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
	q.push({ 0,0,0 });
	dist[0][0][0] = 1;
	bool isCan = false;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, w = q.front().w;
		q.pop();
		if (x == M - 1 && y == N - 1) {
			cout << dist[x][y][w] << '\n';
			isCan = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if (dist[nx][ny][w]) continue;
			if (maze[ny][nx] == 0) {
				dist[nx][ny][w] = dist[x][y][w] + 1;
				q.push({ nx,ny,w });
			}
			if (maze[ny][nx] == 1 && w == 0) {
				dist[nx][ny][1] = dist[x][y][w] + 1;
				q.push({ nx,ny,1 });
			}
		}
	}
	if (!isCan) {
		cout << "-1\n";
	}
}