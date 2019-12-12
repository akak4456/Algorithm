//result:맞았습니다!!
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_LEN = 1000000;
string P;
int pi[MAX_LEN];
vector<int> ret;
void getPartialMatch() {
	int m = P.size();
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (P[begin + matched] == P[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
}
int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> P) {
		if (P == ".")
			break;
		for (int i = 0; i < MAX_LEN; i++)
			pi[i] = 0;
		getPartialMatch();
		int end = P.size() - 1;
		int div = P.size() - pi[end];
		if (pi[end] == 0 || pi[end] % div != 0) {
			cout << "1\n";
		}
		else {
			cout << P.size() / div << '\n';
		}
	}
}