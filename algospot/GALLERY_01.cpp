//result:오답
/*
1
10 9
0 1
1 2
1 3
3 4
3 5
0 6
6 7
7 8
7 9
원래 결과:3
실제 결과:4
*/
#include <iostream>
#include <set>
using namespace std;
int C;
int G, H;
set<int> chosen;
struct Node {
	int idx;
	int sz = 0;
	bool connect[1000] = { false, };
};
Node* node[1000];
int maxConnect() {
	int maxValue = 0;
	int idx = -1;
	for (int i = 0; i < G; i++) {
		//cout << node[i]->sz << endl;
		if (node[i]->sz > maxValue) {
			maxValue = node[i]->sz;
			idx = i;
		}
	}
	return idx;
}
void deleteConnect(int idx) {
	for (int i = 0; i < G; i++) {
		if (node[i]->connect[idx]) {
			chosen.insert(i);
			node[i]->connect[idx] = false;
			node[i]->sz--;
		}
	}
	chosen.insert(idx);
	for (int i = 0; i < G; i++) {
		if (node[idx]->connect[i]) {
			node[idx]->connect[i] = false;
			node[idx]->sz--;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		chosen.clear();
		cin >> G >> H;
		for (int i = 0; i < G; i++) {
			node[i] = new Node;
			node[i]->idx = i;
		}
		for (int i = 0; i < H; i++) {
			int from, to;
			cin >> from >> to;
			node[from]->connect[to] = true;
			node[from]->sz++;
			node[to]->connect[from] = true;
			node[to]->sz++;
		}
		int cnt = 0;
		while (true) {
			int ans = maxConnect();
			if (ans == -1)
				break;
			cnt++;
			deleteConnect(ans);
			/*
			for (int i = 0; i < G; i++) {
				for (int j = 0; j < G; j++) {
					cout << node[i]->connect[j] << ' ';
				}
				cout << endl;
			}
			*/
		}
		cout << cnt + (G - chosen.size()) << endl;
		for (int i = 0; i < G; i++) {
			delete node[i];
		}
	}
}