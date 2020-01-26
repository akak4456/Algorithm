//result:오답
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 987654321;
int K;
string src[15 + 1];
int cache[(1 << 15)][15 + 1];
int overlapCnt(int idx1, int idx2) {
	//idx1:앞 idx2:뒤
	string s1 = src[idx2];
	string s2 = src[idx1];
	for (int length = min(s1.size(), s2.size()); length > 0; length--)
		if (s1.substr(s1.size() - length) == s2.substr(0, length))
			return length;
	return 0;
}
int solve(int used, int last) {
	//cout <<"call:"<< used << " " << src[last] << endl;
	if (used == (1 << K) - 1) {
		//기저사례
		return 0;
	}
	int& ret = cache[used][last];
	if (ret != -1) return ret;
	ret = INF;
	int b, c, ans;
	for (int nxt = 0;nxt < K;nxt++) {
		if ((used & (1 << nxt)) == 0) {
			b = overlapCnt(nxt, last);
			c = src[nxt].size() - b;
			ans = c + solve(used + (1 << nxt), nxt);
			if (ans < ret)
				ret = ans;
		}
	}
	return ret;
}
string reconstruct(int used, int last) {
	if (used == (1 << K) - 1) return "";
	int b, c, ans;
	string ret;
	for (int nxt = 0;nxt < K; nxt++) {
		if ((used & (1 << nxt)) == 0) {
			b = overlapCnt(nxt, last);
			c = src[nxt].size() - b;
			ans = c + solve(used + (1 << nxt), nxt);
			if (ans == solve(used, last)) {
				ret = src[nxt].substr(b)+reconstruct(used + (1 << nxt), nxt);
				//cout << "second:"<<ret << endl;
				return ret;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	cin >> c;
	while (c--) {
		memset(cache, -1, sizeof(cache));
		cin >> K;
		for (int i = 0;i < K;i++) {
			cin >> src[i];
		}
		while (true){
			bool removed = false;
			for (int j = 0; j < K && !removed; j++)
				for (int k = 0; k < K; k++)
					if (j != k && src[j].find(src[k]) != -1){
						src[k] = src[K - 1]; //맨 끝에 있는 string과 위치변경
						K--;
						removed = true;
					}
			if (!removed)
				break;
		}
		src[K] = "";
		cout << solve(0, K) << endl;
		cout << reconstruct(0, K)<< endl;
	}
}