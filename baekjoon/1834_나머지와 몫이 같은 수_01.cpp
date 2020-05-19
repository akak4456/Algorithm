//result:틀렸습니다
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	long long int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += i * (N + 1);
	}
	cout << sum << '\n';
}