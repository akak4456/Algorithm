//result:맞았습니다!!
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_LEN = 360000;
int N;
int pi[MAX_LEN];
string str1, str2;
void getPartialMatch(const string& P) {
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
vector<int> kmpSearch(const string& T,const string& P) {
	int n = T.size(), m = P.size();
	int begin = 0, matched = 0;
	vector<int> ret;
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
	return ret;
}
bool iCanDo(const string& origin,const string& target) {
	return kmpSearch(origin + origin, target).size() > 0;
}
int main(void) {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	str1.resize(MAX_LEN);
	str2.resize(MAX_LEN);
	for (int i = 0; i < MAX_LEN; i++) {
		str1[i] = '0';
		str2[i] = '0';
	}
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		str1[num] = '1';
	}
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		str2[num] = '1';
	}
	getPartialMatch(str2);
	if (iCanDo(str1, str2)) {
		cout << "possible\n";
	}
	else {
		cout << "impossible\n";
	}
}