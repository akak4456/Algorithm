//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	int arr[10];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<int> ans;
	ans.push_back(N);
	for (int i = N - 2; i >= 0; i--) {
		int cnt = arr[i];
		bool inserted = false;
		for (int j = 0; j < ans.size(); j++) {
			if (cnt == 0) {
				inserted = true;
				ans.insert(ans.begin() + j,i+1);
				break;
			}
			else if (i + 1 < ans[j]) {
				cnt--;
			}
		}
		if (!inserted) {
			ans.push_back(i + 1);
		}
		//cout << ans.size() << endl;
	}
	for (int t : ans) {
		cout << t << ' ';
	}
	cout << '\n';
}