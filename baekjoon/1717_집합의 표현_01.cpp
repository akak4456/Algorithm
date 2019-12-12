//result:맞았습니다!!
#include <iostream>
using namespace std;
const int MAX_N = 1000000 + 1;
int n, m;
int parent[MAX_N];
int Find(int x) {
	if (x == parent[x])
		return x;
	int p = Find(parent[x]);
	parent[x] = p;
	return p;
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < MAX_N; i++)
		parent[i] = i;
	while (m--) {
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 0) {
			Union(a, b);
		}
		else if (t == 1) {
			if (Find(a) == Find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}