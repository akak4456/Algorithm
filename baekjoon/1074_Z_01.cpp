//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int solve(int len,int r, int c) {
	//cout << len << ' ' << r << ' ' << c << endl;
	if (len == 2) {
		if (r == 0) {
			if (c == 0)
				return 0;
			else if (c == 1)
				return 1;
		}else if (r == 1) {
			if (c == 0)
				return 2;
			else if (c == 1)
				return 3;
		}
	}
	int div = len/2;
	if (r < div && c < div) {
		return solve(div, r, c);
	}
	else if (r < div && c >= div) {
		return solve(div, r, c-div)+div*div;
	}
	else if (r >= div && c < div) {
		return solve(div, r - div, c)+ div * div *2;
	}
	else if (r >= div && c >= div) {
		return solve(div, r - div, c - div)+ div * div *3;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, r, c;
	cin >> N >> r >> c;
	cout << solve((1 << N), r, c) << '\n';
}