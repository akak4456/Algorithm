//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M, N;
	cin >> M >> N;
	vector<int> result;
	for (int num = M; num <= N; num++) {
		int sq = 1;
		while (sq * sq < num) {
			sq++;
		}
		//cout << sq << endl;
		if (sq * sq == num)
			result.push_back(num);
	}
	if (result.empty()) {
		cout << "-1\n";
	}
	else {
		int sum = 0;
		for (int i : result)
			sum += i;
		cout << sum << '\n' << result[0] << '\n';
	}
}