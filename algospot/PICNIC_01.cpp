//result:정답
#include <iostream>
#include <vector>
using namespace std;
int C, n, m;
int COUNT;
int relation[10][10];
void makeFriend(vector<int> men) {
	if (men.size() == 0) {
		COUNT++;
		return;
	}
	for (int i = 1; i < men.size(); i++) {
		if (relation[men[0]][men[i]] == 1||relation[men[i]][men[0]]==1) {
			vector<int> k;
			k.clear();
			for (int t = 0; t < men.size(); t++) {
				if (men[t] != men[0] && men[t] != men[i]) {
					k.push_back(men[t]);
				}
			}
			makeFriend(k);
		}
	}
}

int main() {
	cin >> C;
	for (int i = 1; i <= C; i++) {
		COUNT = 0;
		cin >> n >> m;
		for (int p1 = 0; p1 < 10; p1++) {
			for (int p2 = 0; p2 < 10; p2++) {
				relation[p1][p2] = 0;
			}
		}
		for (int j = 1; j <= m; j++) {
			int t1, t2;
			cin >> t1 >> t2;
			relation[t1][t2] = 1;
			relation[t2][t1] = 1;
		}
		vector<int> men;
		men.clear();
		for (int j = 0; j < n; j++) {
			men.push_back(j);
		}
		makeFriend(men);
		cout << COUNT << endl;
	}
}