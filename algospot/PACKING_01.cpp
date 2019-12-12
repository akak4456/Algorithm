//result:정답
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Product {
	string name;
	int w;
	int p;
};
Product products[100];
int C;
int N;
int W;
int cache[1001][100];
int pack(int capacity, int item) {
	if (item == N) {
		return 0;
	}
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;
	ret = pack(capacity, item + 1);
	if (capacity >= products[item].w) {
		ret = max(ret, pack(capacity - products[item].w, item + 1) + products[item].p);
	}
	return ret;
}
void reconstruct(int capacity, int item, vector<string>& picked) {
	if (item == N) return;
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(products[item].name);
		reconstruct(capacity - products[item].w, item + 1, picked);
	}
}
int main() {
	cin >> C;
	while (C--) {
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 100; j++) {
				cache[i][j] = -1;
			}
		}
		cin >> N >> W;
		for (int i = 0; i < N; i++) {
			cin >> products[i].name >> products[i].w >> products[i].p;
		}
		vector<string> result;
		result.clear();
		reconstruct(W, 0, result);
		cout << pack(W, 0) <<" "<<result.size()<< endl;
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << endl;
		}
	}
}