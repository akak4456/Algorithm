//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int E, S, M;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> E >> S >> M;
	if ((6916 * E + 4845 * S + 4200 * M) % 7980 == 0)
		cout << "7980\n";
	else
		cout << (6916 * E + 4845 * S + 4200 * M) % 7980 << '\n';
}