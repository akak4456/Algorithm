//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
const string matched[10] = {
	"black","brown","red","orange","yellow","green","blue","violet","grey","white"
};
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string A, B, C;
	cin >> A >> B >> C;
	int val = 0;
	for (int i = 0; i < 10; i++) {
		if (matched[i] == A) {
			val += i * 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (matched[i] == B) {
			val += i;
		}
	}
	string ans = to_string(val);
	for (int i = 0; i < 10; i++) {
		long long int prod = 1;
		if (matched[i] == C && val > 0) {
			/*
			val > 0인 조건을 빼먹었음
			이 조건을 빼면
			black black brown을 입력하면
			00과 같이 출력된다
			*/
			for (int j = 0; j < i; j++) {
				ans = ans + "0";
			}
		}
	}
	cout << ans << '\n';
}