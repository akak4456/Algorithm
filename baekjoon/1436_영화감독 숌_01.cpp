//result:틀렸습니다
#include <iostream>
#include <string>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int cnt = 0;
	int num = 666;
	while (true) {
		string s = to_string(num);
		for (int i = 0; i <= s.size() - 3; i++) {
			if (s[i] == '6' && s[i+1] == '6' && s[i+2] == '6') {
				cnt++;
			}
		}
		if (cnt == N)
			break;
		num++;
	}
	cout << num;
}