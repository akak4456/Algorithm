//result:맞았습니다!!
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
	int M, N, K;
	int board[100][100];
	memset(board, 0, sizeof(board));
	cin >> M >> N >> K;
	while (K--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				board[y][x] = 1;
			}
		}
	}
	
	vector<int> result;
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			if (board[y][x] == 0) {
				//cout << y << ' ' << x << endl;
				int cnt = 1;
				queue<pair<int, int> >q;
				q.push(make_pair(x, y));
				while (!q.empty()) {
					
					pair<int, int> po = q.front();
					q.pop();
					int nx = po.first;
					int ny = po.second;
					//cout << nx << ' ' << ny << endl;
					board[ny][nx] = 1;
					if (ny - 1 >= 0 && board[ny - 1][nx] == 0) {
						cnt++;
						board[ny - 1][nx] = 1;
						q.push(make_pair(nx, ny - 1));
					}
					if (ny + 1 < M && board[ny + 1][nx] == 0) {
						cnt++;
						board[ny + 1][nx] = 1;
						q.push(make_pair(nx, ny + 1));
					}
					if (nx - 1 >= 0 && board[ny][nx - 1] == 0) {
						cnt++;
						board[ny][nx - 1] = 1;
						q.push(make_pair(nx - 1, ny));
					}
					if (nx + 1 < N && board[ny][nx + 1] == 0) {
						cnt++;
						board[ny][nx + 1] = 1;
						q.push(make_pair(nx + 1, ny));
					}
				}
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int t : result) {
		cout << t << ' ';
	}
	cout << '\n';
}