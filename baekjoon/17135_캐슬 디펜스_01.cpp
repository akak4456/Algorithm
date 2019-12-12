//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 987654321;
struct Point {
	int x, y;
};
struct Archer {
	int pos[3];
};
int N, M, D;
int origin[15][15];
int game[15][15];
int best;
vector<Archer> archers;
void makeArcher(vector<int> ans,int cnt) {
	if (cnt == 0) {
		Archer archer;
		archer.pos[0] = ans[0];
		archer.pos[1] = ans[1];
		archer.pos[2] = ans[2];
		archers.push_back(archer);
		return;
	}
	for (int i = 0; i < M; i++) {
		if (!ans.empty() && i <= ans.back()) {
			continue;
		}
		ans.push_back(i);
		makeArcher(ans, cnt - 1);
		ans.pop_back();
	}
}
int diff(const Point& a,const Point& b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}
int attack(Archer archer) {
	int ret = 0;
	for (int idx = 0; idx < 3; idx++) {
		int minDist = INF;
		int minY = -1, minX = -1;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (game[y][x] != 0) {
					Point archerPoint;
					archerPoint.x = archer.pos[idx];
					archerPoint.y = N;
					Point enemyPoint;
					enemyPoint.x = x;
					enemyPoint.y = y;
					int res = diff(enemyPoint, archerPoint);
					if (res <= D && res <= minDist) {
						if (res == minDist) {
							if (x < minX) {
								minY = y;
								minX = x;
							}
						}
						else {
							minY = y;
							minX = x;
						}
						minDist = res;
					}
				}
			}
		}
		if(minY != -1&&game[minY][minX] == 1){
			ret++;
			game[minY][minX] = 2;
		}
	}
	return ret;
}
void move() {
	for (int y = N-1; y > 0; y--) {
		for (int x = 0; x < M; x++) {
			if (game[y - 1][x] == 1)
				game[y][x] = 1;
			else
				game[y][x] = 0;
		}
	}
	for (int x = 0; x < M; x++)
		game[0][x] = 0;
}
int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> origin[i][j];
		}
	}
	vector<int> tmp;
	makeArcher(tmp,3);
	for (int i = 0; i < archers.size(); i++) {
		//cout << archers[i].pos[0] << ' ' << archers[i].pos[1] << ' ' << archers[i].pos[2] << endl;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				game[y][x] = origin[y][x];
			}
		}
		int ans = 0;
		for (int y = 0; y < N+1; y++) {
			ans += attack(archers[i]);
			move();
		}
		if (ans > best)
			best = ans;
	}
	cout << best << '\n';
}