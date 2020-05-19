//result:틀렸습니다
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
	long long int S;
	int cnt = 0;
	long long int sum = 0;
	cin >> S;
	for (long long int i = 1; i <= S; i++) {
		if (sum + i*2 <= S) {
			sum += i;
			cnt++;
		}
		else {
			break;
		}
	}
	if (sum < S)
		cnt++;
	cout << cnt << endl;
}