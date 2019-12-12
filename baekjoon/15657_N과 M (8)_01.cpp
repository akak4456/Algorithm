//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(vector<int> src,vector<int> ans,int cnt){
	if (cnt == 0) {
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < src.size(); i++) {
		if (!ans.empty()&&src[i] < ans.back())
			continue;
		for (int j = 0; j < src.size(); j++) {
			if (i == j) {
				ans.push_back(src[j]);
				break;
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
}