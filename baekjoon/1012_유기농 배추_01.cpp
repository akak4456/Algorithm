//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int T;
int M, N, K;
int land[50][50];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				land[y][x] = 0;
		for (int i = 0; i < K; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			land[t2][t1] = 1;
		}
		int cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (land[y][x] == 1) {
					cnt++;
					land[y][x] = 2;
					queue<pair<int,int> > q;
					q.push(make_pair(y, x));
					while (!q.empty()) {
						pair<int,int> tmp = q.front();
						q.pop();
						int nx = tmp.second, ny = tmp.first;
						land[ny][nx] = 2;
						if (ny - 1 >= 0 && land[ny - 1][nx] == 1) {
							land[ny - 1][nx] = 2;
							q.push(make_pair(ny - 1, nx));
						}
						if (ny + 1 < N && land[ny + 1][nx] == 1) {
							land[ny + 1][nx] = 2;
							q.push(make_pair(ny + 1, nx));
						}
						if (nx - 1 >= 0 && land[ny][nx - 1] == 1) {
							land[ny][nx - 1] = 2;
							q.push(make_pair(ny, nx - 1));
						}
						if (nx + 1 < M && land[ny][nx + 1] == 1) {
							land[ny][nx + 1] = 2;
							q.push(make_pair(ny, nx + 1));
						}
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}