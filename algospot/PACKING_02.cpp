//result:오답
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 100 + 1;
const int MAX_W = 1000 + 1;
const int MAX_V = 1000 + 1;
struct Product {
	string name;
	int v;
	int want;
};
int N, W;
Product product[MAX_N];
int cache[MAX_N];
int choose[MAX_N];
int solve(int idx, int weight) {
	if (idx == N)
		return 0;
	int& ret = cache[idx];
	if (ret != -1) return ret;
	ret = 0;
	if (weight - product[idx].v >= 0 &&product[idx].want + solve(idx + 1, weight - product[idx].v) > ret) {
		ret = product[idx].want + solve(idx + 1, weight - product[idx].v);
		choose[idx] = 1;
	}
	if (solve(idx + 1, weight) > ret) {
		ret = solve(idx + 1, weight);
		choose[idx] = 0;
	}
	return ret;
}
vector<int> result;
void makeResult(int idx) {
	if (idx == N) return;
	if (choose[idx] == 1) {
		result.push_back(idx);
	}
	makeResult(idx + 1);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	while (C--) {
		result.clear();
		memset(cache, -1, sizeof(cache));
		cin >> N >> W;
		for (int i = 0; i < N; i++) {
			cin >> product[i].name >> product[i].v >> product[i].want;
		}
		cout << solve(0, W) << ' ';
		makeResult(0);
		cout << result.size() << '\n';
		for (int idx : result) {
			cout << product[idx].name << '\n';
		}

	}
}