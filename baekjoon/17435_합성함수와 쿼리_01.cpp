//result:맞았습니다!!
#include <iostream>
using namespace std;
const int MAX_M = 200000+1;
int M;
int fx[MAX_M];
int Q;
int par[MAX_M][21];
void f() {
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= M; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> fx[i];
		par[i][0] = fx[i];
	}
	f();
	cin >> Q;
	while (Q--) {
		int n, x;
		cin >> n >> x;
		for (int i = 20; i >= 0; i--) {
			if ((1 << i) <= n) {
				n -= (1 << i);
				x = par[x][i];
			}
		}
		cout << x << '\n';
	}
}