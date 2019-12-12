//result:맞았습니다!!
#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int count = 0;
	for (int n = 1; n <= N; n++) {
		int tmpN = n;
		int t[4] = { -1,-1,-1,-1 };
		for (int i = 0; i < 4; i++) {
			t[i] = tmpN % 10;
			tmpN /= 10;
			if (tmpN == 0) {
				break;
			}
		}
		int dif = 0;
		bool start = false;
		for (int i = 0; i < 3; i++) {
			if (t[i + 1] == -1) {
				count++;
				break;
			}
			else if (!start) {
				start = true;
				dif = t[i + 1] - t[i];
			}
			else if (dif != t[i + 1]-t[i]) {
				break;
			}
		}
	}
	cout << count << endl;
}