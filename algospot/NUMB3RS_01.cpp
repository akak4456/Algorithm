//result:오답
#include <iostream>
#include <iomanip>
using namespace std;

int C;
int N, D, P, Q;
double cache[51][101];
int connected[51][51], deg[51];
double search(int here, int days) {
	if (days == D) {
		return (here == Q ? 1.0 : 0.0);
	}
	double& ret = cache[here][days];
	if (ret != -1) return ret;
	ret = 0.0;
	for (int there = 0; there < N; there++) {
		if (connected[here][there] == 1) {
			ret += search(there, days + 1) / deg[here];
		}
	}
	return ret;
}
int main() {
	cin >> C;
	while (C--) {
		cin >> N >> D >> P;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> connected[i][j];
				if (connected[i][j] == 1) {
					deg[i]++;
				}
			}
		}
		int t;
		cin >> t;
		while (t--) {
			for (int i = 0; i < 51; i++) {
				for (int j = 0; j < 101; j++) {
					cache[i][j] = -1;
				}
			}
			cin >> Q;
			cout << setprecision(8)<<search(P, 0) << " ";
		}
		cout << endl;
	}
}