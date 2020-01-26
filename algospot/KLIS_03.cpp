//result:정답
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 2000000000 + 1;
int n,k;
int cache[501],cacheCnt[501], S[500];
int lis(int start) {
	int& ret = cache[start + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (start == -1 || S[start] < S[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}
int count(int start) {
	if (lis(start) == 1) return 1;
	int& ret = cacheCnt[start + 1];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = start + 1; next < n; next++) {
		if ((start == -1 || S[start] < S[next]) && lis(start) == lis(next) + 1)
			ret = min<long long>(MAX, (long long)ret + count(next));
	}
	return ret;
}
vector<int> result;
vector<pair<int, int> > SOrdered;
void reconstruct(int start, int skip) {
	if (start != -1) result.push_back(S[start]);
	vector<pair<int, int> > followers;
	for (int i = 0; i < n; i++) {
		if (start == -1 || S[start] < SOrdered[i].first) {
			if (lis(start) == lis(SOrdered[i].second) + 1) {
				followers.push_back(make_pair(SOrdered[i].first, SOrdered[i].second));
			}
		}
	}
	for (int i = 0; i < followers.size(); i++) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip)
			skip -= cnt;
		else {
			reconstruct(idx, skip);
			break;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	while (C--) {
		result.clear();
		SOrdered.clear();
		memset(cache, -1, sizeof(cache));
		memset(cacheCnt, -1, sizeof(cacheCnt));
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> S[i];
		cout << lis(-1) - 1 << '\n';
		for (int i = 0; i < n; i++) {
			SOrdered.push_back(make_pair(S[i], i));
		}
		sort(SOrdered.begin(), SOrdered.end());
		reconstruct(-1,k-1);
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
	}
}