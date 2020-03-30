//result:틀렸습니다
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
	int n;
	cin >> n;
	int q1, q2;
	cin >> q1 >> q2;
	int m;
	cin >> m;
	int matrix[101][101];
	int visited[101];
	memset(matrix, 0, sizeof(matrix));
	memset(visited, 0, sizeof(visited));
	while (m--) {
		int x, y;
		cin >> x >> y;
		matrix[x][y] = matrix[y][x] = 1;
	}
	queue<pair<int, int> >q;
	q.push(make_pair(q1, 0));
	while (!q.empty()) {
		pair<int, int> fr = q.front();
		q.pop();
		int node = fr.first;
		int cnt = fr.second;
		visited[node] = 1;
		if (node == q2) {
			cout << cnt << '\n';
			break;
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0 && matrix[node][i] == 1) {
				visited[i] = 1;
				q.push(make_pair(i, cnt + 1));
			}
		}
	}
	cout << "-1\n";
}