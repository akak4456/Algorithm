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
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int cnt = N/5;
	while (cnt > 0 && (N - cnt * 5) % 3 != 0) {
		cnt--;
	}
//	cout << cnt << endl;
	if (cnt == 0 && N % 3 != 0) {
		cout << "-1\n";
	}
	else {
		cout << ((N-cnt*5) / 3) + cnt << '\n';
	}
}