//result:오답
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 987654321;
int k;
string src[15 + 1];
int cache[1 << 15][15 + 1];
int overlapCnt(int idx1, int idx2) {
	//idx1:앞 idx2:뒤
	int ret = 0;
	for (int cnt = 1;cnt <= min(src[idx1].size(), src[idx2].size());cnt++) {
		int i = 0, j = src[idx2].size() - cnt;
		bool isCan = true;
		for (int i = 0;i < cnt;i++) {
			if (src[idx1][i] != src[idx2][j]) {
				isCan = false;
				break;
			}
			j++;
		}
		if (isCan)
			ret = cnt;
	}
	if (src[idx1].size() > src[idx2].size()) {
		int tmp = idx1;
		idx1 = idx2;
		idx2 = tmp;
	}
	if (src[idx2].find(src[idx1]) != std::string::npos) {
		return src[idx1].size();
	}
	return ret;
}
int solve(int used, int idx1) {
	/*앞에 문자열 idx1, 뒤에 문자열 idx2가 있는 문자열이 있다.
	지금까지 used가 사용되었을 때 나머지 문자들을 이용해서
	만들 수있는 최소 문자열의 길이는?
	*/
	//cout <<"call:"<< used << " " << src[idx1] << " " << src[idx2] << endl;
	if (used == (1 << k) - 1) {
		//기저사례
		//cout << "ret: 0" << endl;
		return 0;
	}
	int& ret = cache[used][idx1];
	if (ret != -1) return ret;
	ret = INF;
	int b, c, ans;
	for (int nxt = 0;nxt < k;nxt++) {
		if ((used & (1 << nxt)) == 0) {
			b = overlapCnt(nxt, idx1);
			c = src[nxt].size() - b;
			ans = c + solve(used + (1 << nxt), nxt);
			if (ans < ret)
				ret = ans;
		}
	}
	//cout << "ret: " << ret << endl;
	return ret;
}
string reconstruct(int used, int idx1) {
	if (used == (1 << k) - 1) return "";
	int b, c, ans;
	string ret;
	for (int nxt = 0;nxt < k; nxt++) {
		if ((used & (1 << nxt)) == 0) {
			/*
			b = overlapCnt(idx1, nxt);
			c = src[nxt].size() - b;
			ans = c + solve(used + (1 << nxt), nxt, idx2);
			if (ans == solve(used, idx1, idx2)) {
				ret =   reconstruct(used + (1 << nxt), nxt, idx2) + src[nxt].substr(0,c);
				//cout << "first:"<<ret << endl;
				if (idx1 == 0 && idx2 == 0) {
					ret = ret + src[0];
				}
				return ret;
			}
			*/
			b = overlapCnt(nxt, idx1);
			c = src[nxt].size() - b;
			ans = c + solve(used + (1 << nxt), nxt);
			if (ans == solve(used, idx1)) {
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
		cin >> k;
		for (int i = 0;i < k;i++) {
			cin >> src[i];
		}
		//cout << solve(1, 0, 0) + src[0].size() << endl;
		cout << reconstruct(0, k)<< endl;
	}
}