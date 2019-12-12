//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C;
int N, K;
int S[500];
int cache[501];
int cacheCnt[501];
int L;
const int MAX = 2000000000 + 1;
vector<int> result;
int lis3(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;
	ret = 1;
	for (int next = start + 1; next < N; next++) {
		if (start == -1 || S[start] < S[next]) {
			int ans = lis3(next) + 1;
			if (ans > ret) {
				ret = ans;
			}
		}
	}
	return ret;
}
int count(int start) {
	if (lis3(start) == 1) return 1;
	int& ret = cacheCnt[start + 1];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = start + 1; next < N; next++) {
		if ((start == -1 || S[start] < S[next]) && lis3(start) == lis3(next) + 1) {
			ret = min<long long>(MAX, (long long)ret + count(next));
		}
	}
	return ret;
}
void reconstruct(int start, int skip) {
	if (start != -1) {
		result.push_back(S[start]);
	}
	vector<pair<int, int> > followers;
	for (int next = start + 1; next < N; next++) {
		if ((start == -1 || S[start] < S[next]) && lis3(start) == lis3(next) + 1) {
			followers.push_back(make_pair(S[next], next));
		}
	}
	sort(followers.begin(), followers.end());
	for (int i = 0; i < followers.size(); i++) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip) {
			skip -= cnt;
		}
		else {
			reconstruct(idx, skip);
			break;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		result.clear();
		for (int i = 0; i < 501; i++) {
			cache[i] = -1;
			cacheCnt[i] = -1;
		}
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> S[i];
		}
		L = lis3(-1);
		cout << (L -1) << endl;
		reconstruct(-1, K - 1);
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << " ";
		}
		cout << endl;
	}
}