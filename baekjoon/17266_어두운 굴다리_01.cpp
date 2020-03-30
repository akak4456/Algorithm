//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N;
int M;
vector<int> x;
bool decision(int height) {
	//cout << height << endl;
	int minPos = 0;
	for (int i = 0; i < x.size(); i++) {
		if (minPos < x[i] - height)
			return false;
		minPos = x[i] + height;
	}
	return minPos >= N;
}
int solve() {
	int lo = -1, hi = 100001;
	for (int i = 0; i < 30; i++) {
		int mid = (lo + hi) / 2;
		if (decision(mid)) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	return hi;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> M;
	x.resize(M);
	for (int i = 0; i < M; i++)
		cin >> x[i];
	cout << solve() << '\n';
}