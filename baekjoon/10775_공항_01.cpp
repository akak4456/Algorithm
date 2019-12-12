//result:맞았습니다!!
#include <iostream>
using namespace std;
const int MAX_N = 100001;
int parent[MAX_N];
int G, P;
int find(int p) {
	if (parent[p] == p) return p;
	else return parent[p] = find(parent[p]);
}
void uni(int p, int q) {
	p = find(p);
	q = find(q);
	parent[p] = q;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i < MAX_N; i++) {
		parent[i] = i;
	}
	cin >> G;
	cin >> P;
	int ans = 0;
	for (int i = 0; i < P; i++) {
		int t1;
		cin >> t1;
		int docking = find(t1);
		if (docking != 0) {
			uni(docking, docking - 1);
			ans++;
		}
		else {
			cout << ans << '\n';
			return 0;
		}
	}
	cout << ans <<'\n';
}