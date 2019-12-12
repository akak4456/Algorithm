//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > input;
int rankNum[50];
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		input.push_back(make_pair(t1, t2));
	}
	for (int idx = 0; idx < N; idx++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (i == idx)continue;
			if (input[i].first > input[idx].first && input[i].second > input[idx].second)
				cnt++;
		}
		rankNum[idx] = cnt + 1;
	}
	for (int i = 0; i < N; i++)
		cout << rankNum[i] << ' ';
	cout << endl;
}