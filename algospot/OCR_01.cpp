//result:정답
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int n, m;
int R[100];
double T[501][501];
double M[501][501];
int choice[102][502];
string corpus[501];
double cache[102][502];

double recognize(int segment, int previousMatch) {
	if (segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;
	ret = -1e200;
	int& choose = choice[segment][previousMatch];

	for (int thisMatch = 0; thisMatch < m; thisMatch++) {
		double cand = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment + 1, thisMatch);
		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}

string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
	string ret = corpus[choose];

	if (segment < n - 1)
		ret = ret + " " + reconstruct(segment + 1, choose);
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> corpus[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> T[m][i];
		T[m][i] = log(T[m][i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> T[i][j];
			T[i][j] = log(T[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
			M[i][j] = log(M[i][j]);
		}
	}
	while (q--) {
		for (int i = 0; i < 102; i++) {
			for (int j = 0; j < 502; j++) {
				cache[i][j] = 1.0;
			}
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 0; j < m; j++) {
				if (tmp == corpus[j]) {
					R[i] = j;
					break;
				}
			}
		}
		recognize(0, m);
		cout << reconstruct(0, m) << '\n';
	}
}