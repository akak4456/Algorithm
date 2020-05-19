//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
const int MOD = 1000000000;
int fib[1000001];
int landsea[50][50];
bool visited[50][50];
int w, h;
void dfs(int y, int x) {
	if (landsea[y][x] == 0)
		return;
	visited[y][x] = true;
	if (y - 1 >= 0) {
		if (x - 1 >= 0) {
			if (!visited[y - 1][x - 1])
				dfs(y - 1, x - 1);
		}
		if (!visited[y - 1][x])
			dfs(y - 1, x);
		if (x + 1 < w) {
			if (!visited[y - 1][x + 1])
				dfs(y - 1, x + 1);
		}
	}
	if (x - 1 >= 0) {
		if (!visited[y][x - 1])
			dfs(y , x - 1);
	}
	if (x + 1 < w) {
		if (!visited[y][x + 1])
			dfs(y, x + 1);
	}
	if (y + 1 < h) {
		if (x - 1 >= 0) {
			if (!visited[y + 1][x - 1])
				dfs(y + 1, x - 1);
		}
		if (!visited[y + 1][x])
			dfs(y + 1, x);
		if (x + 1 < w) {
			if (!visited[y + 1][x + 1])
				dfs(y + 1, x + 1);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> w >> h) {
		if (w == 0 && h == 0)
			break;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> landsea[i][j];
				visited[i][j] = false;
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j]&&landsea[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}