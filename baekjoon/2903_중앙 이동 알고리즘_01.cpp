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
	cin >> N;
	int width = 2;
	int prod = 1;
	for (int step = 1; step <= N; step++) {
		width += prod;
		prod *= 2;
		//cout << width << endl;
	}
	cout << width * width << '\n';
}