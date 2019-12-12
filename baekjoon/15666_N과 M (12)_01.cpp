//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
set<vector<int>> ansSet;
void solve(vector<int> src,vector<int> ans,int cnt){
	if (cnt == 0) {
		ansSet.insert(ans);
		return;
	}
	for (int i = 0; i < src.size(); i++) {
		if (!ans.empty() && src[i] < ans.back())
			continue;
		//vector<int> newSrc;
		for (int j = 0; j < src.size(); j++) {
			if (i == j) {
				ans.push_back(src[j]);
				break;
			}
			else {
				//newSrc.push_back(src[j]);
			}
		}
		solve(src, ans, cnt - 1);
		ans.pop_back();
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> input;
	input.resize(N);
	for (int i = 0; i < N; i++)
		cin >> input[i];
	sort(input.begin(), input.end());
	vector<int> tmp;
	solve(input, tmp,M);
	for (set<vector<int> >::iterator it = ansSet.begin(); it != ansSet.end(); it++) {
		for (int i : *it) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}