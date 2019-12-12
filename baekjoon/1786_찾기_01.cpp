//result:맞았습니다!!
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_LEN = 1000000;
string T, P;
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
void kmpSearch() {
	int n = T.size(), m = P.size();
	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && T[begin + matched] == P[matched]) {
			matched++;
			if (matched == m) {
				ret.push_back(begin + 1);
			}
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
int main(void){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin, T);
	getline(cin, P);
	getPartialMatch();
	kmpSearch();
	cout << ret.size() << '\n';
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << '\n';
}