//result:맞았습니다!!
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 200 + 1;
int N, M;
int adj[MAX_N][MAX_N];
int parent[MAX_N];
int Find(int x) {
	if (x == parent[x])
		return x;
	int p = Find(parent[x]);
	parent[x] = p;
	return p;
}
void Union(int x, int y) {
	//cout << "before:" << x << ' ' << y << endl;
	x = Find(x);
	y = Find(y);
	//cout << "after:"<<x << ' ' << y << endl;
	if (x != y) {
		parent[y] = x;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < MAX_N; i++)
		parent[i] = i;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> adj[i][j];
	for (int i = 1; i <= N; i++)
		for (int j = i+1; j <= N; j++) {
			if (adj[i][j] == 1) {
				Union(i, j);
			}
		}
	bool isCan = true;
	vector<int> route;
	route.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> route[i];
		if (i >= 1) {
			if (Find(route[i - 1]) != Find(route[i])) {
				isCan = false;
			}
		}
	}
	if (isCan)
		cout << "YES\n";
	else
		cout << "NO\n";
}