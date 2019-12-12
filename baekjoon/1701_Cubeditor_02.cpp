//result:맞았습니다!!
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX_LEN = 5000;
string T, P;
int pi[MAX_LEN][MAX_LEN];
vector<int> ret;
void getPartialMatch() {
	int step = 0;
	while (P.size() > 1) {
		int m = P.size();
		int begin = 1, matched = 0;
		while (begin + matched < m) {
			if (P[begin + matched] == P[matched]) {
				matched++;
				pi[step][begin + matched - 1] = matched;
			}
			else {
				if (matched == 0)
					begin++;
				else {
					begin += matched - pi[step][matched - 1];
					matched = pi[step][matched - 1];
				}
			}
		}
		step++;
		P.erase(P.begin());
	}
}
/*
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
*/
int main(void){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	//getline(cin, T);
	getline(cin, P);
	getPartialMatch();
	//kmpSearch();
	int maxLen = -1;
	for (int i = 0; i < MAX_LEN; i++) {
		for (int j = 0; j < MAX_LEN; j++) {
			if (maxLen < pi[i][j])
				maxLen = pi[i][j];
		}
	}
	cout << maxLen << '\n';
}