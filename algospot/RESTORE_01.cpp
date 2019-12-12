//result:오답
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 15;
int k;
string word[MAX_N];
int cache[MAX_N][1 << MAX_N], overlap[MAX_N][MAX_N];
void overlapCalc() {
	for (int idx1 = 0; idx1 < k; idx1++) {
		for (int idx2 = idx1+1; idx2 < k; idx2++) {
			string string1 = word[idx1];
			string string2 = word[idx2];
			int i = string1.size() - 1;
			int j = 0;
			int result = 0;
			for (int i = 1; i <= string1.size(); i++) {
				string tmp1 = string1.substr(string1.size()-i,i);
				string tmp2 = string2.substr(0,i);
				if (tmp1 == tmp2) {
					result = i;
				}
			}
			overlap[idx1][idx2] = result;
		}
	}
}
int restore(int last, int used) {
	if (used == (1 << k) - 1) return 0;
	int& ret = cache[last][used];
	if (ret != -1) return ret;
	ret = 0;
	for (int next = 0; next < k; next++) {
		if ((used & (1 << next)) == 0) {
			int cand = overlap[last][next] + restore(next, used + (1 << next));
			ret = max(ret, cand);
		}
	}
	return ret;
}
string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return "";
	for (int next = 0; next < k; next++) {
		if (used & (1 << next)) continue;
		int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];
		if (restore(last, used) == ifUsed) {
			return (word[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next)));
		}
	}
	return "!!!";
}
int C;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < (1 << MAX_N); j++) {
				cache[i][j] = -1;
			}
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> word[i];
		}
		overlapCalc();
		for(int i=0;i<k;i++){
			restore(i, 0);
		}
		string ans;
		for (int i = 0; i < k; i++) {
			string tmp = reconstruct(i, 0);
			if (tmp != "!!!") {
				ans = tmp;
			}
		}
		cout << ans << endl;
	}
}