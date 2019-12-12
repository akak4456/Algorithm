//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include <stack>
using namespace std;
const int MAX_N = 1000000;
const int INF = 987654321;
int N;
int lis[MAX_N + 1];
int S[MAX_N + 1];
pair<int, int> arr[MAX_N + 1];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> S[i];
	int plis = 0;
	int pArr = 1;
	lis[0] = S[0];
	arr[0].first = 0;
	arr[0].second = S[0];
	while (pArr < N) {
		if (lis[plis] < S[pArr]) {
			lis[++plis] = S[pArr];
			arr[pArr].first = plis;
			arr[pArr].second = S[pArr];
		}
		else {
			int pos = lower_bound(lis, lis + plis, S[pArr]) - lis;
			lis[pos] = S[pArr];
			arr[pArr].first = pos;
			arr[pArr].second = S[pArr];
		}
		pArr++;
	}
	cout << plis + 1 << endl;
	stack<int> s;
	int t = plis;
	for (int k = N - 1; k >= 0; k--) {
		if (t == arr[k].first) {
			s.push(arr[k].second);
			t--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}
