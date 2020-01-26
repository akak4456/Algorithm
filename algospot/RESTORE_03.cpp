//result:시간초과
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int INF = 987654321;
int k;
string src[15];
int cache[1 << 15][15][15];
int overlapCnt(int idx1, int idx2) {
	//idx1:앞 idx2:뒤
	int ret = 0;
	for (int i = 0,j=src[idx2].size()-1;i < src[idx1].size()&&j>=0;i++,j--) {
		if (src[idx1][i] != src[idx2][j]) {
			break;
		}
		else {
			ret++;
		}
	}
	return ret;
}
int solve(int used, int idx1, int idx2) {
	/*앞에 문자열 idx1, 뒤에 문자열 idx2가 있는 문자열이 있다.
	이때 최대 overlap 길이는 어떻게 되겠는가?
	*/
	//cout << used << " " << idx1 << " " << idx2 << endl;
	if (used == (1 << k) - 1) {
		//기저사례
		return 0;
	}
	int& ret = cache[used][idx1][idx2];
	if (ret != -1) return ret;
	ret = INF;
	for (int nxt = 0;nxt < k;nxt++) {
		if ((used & (1 << nxt)) == 1)
			continue;
		int b = overlapCnt(nxt, idx1);
		int a = src[idx1].size() - b;
		int c = src[nxt].size() - b;
		cout << b<<" "<<src[idx1] << " " << src[nxt] << " "<<(a + b + c) << endl;
		int ans = (a + b + c) + solve(used | (1 << nxt), nxt, idx2);
		//cout << "first:"<<ans << endl;
		if (ans < ret)
			ret = ans;
		b = overlapCnt(idx2, nxt);
		a = src[nxt].size() - b;
		c = src[idx2].size() - b;
		ans = (a + b + c) + solve(used | (1 << nxt), idx1, nxt);
		//cout << "second:"<<ans << endl;
		if (ans < ret)
			ret = ans;
	}
	return ret;
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
		cout << solve(1, 0, 0);
	}
}