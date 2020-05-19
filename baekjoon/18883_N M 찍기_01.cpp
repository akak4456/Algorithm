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
	int N, M;
	cin >> N >> M;
	int step = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << step;
			if (j < M - 1)
				cout << ' ';
			step++;
		}
		cout << '\n';
	}
}