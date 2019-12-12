//result:맞았습니다!!
#include <iostream>
#include <string>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	string s;
	int cnt = 0;
	int idx = 0;
	cin >> s;
	while (idx < s.size()) {
		if (s[idx] == 'c') {
			idx++;
			if (s[idx] == '=') {
				cnt++;
				idx++;
			}
			else if (s[idx] == '-') {
				cnt++;
				idx++;
			}
			else {
				cnt++;
			}
		}
		else if (s[idx] == 'd') {
			idx++;
			if (s[idx] == 'z') {
				idx++;
				if (s[idx] == '=') {
					idx++;
					cnt++;
				}
				else {
					cnt += 2;
				}
			}
			else if (s[idx] == '-') {
				cnt++;
				idx++;
			}
			else {
				cnt++;
			}
		}
		else if (s[idx] == 'l') {
			idx++;
			if (s[idx] == 'j') {
				cnt++;
				idx++;
			}
			else {
				cnt++;
			}
		}
		else if (s[idx] == 'n') {
			idx++;
			if (s[idx] == 'j') {
				cnt++;
				idx++;
			}
			else {
				cnt++;
			}
		}
		else if (s[idx] == 's') {
			idx++;
			if (s[idx] == '=') {
				cnt++;
				idx++;
			}
			else {
				cnt++;
			}
		}
		else if (s[idx] == 'z') {
			idx++;
			if (s[idx] == '=') {
				cnt++;
				idx++;
			}
			else {
				cnt++;
			}
		}
		else {
			cnt++;
			idx++;
		}
	}
	cout << cnt << '\n';
}