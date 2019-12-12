//result:맞았습니다!!
#include <iostream>
#include <cmath>
using namespace std;
int cnt[1001];
int cnt2[1001];
int main() {
	std::ios::sync_with_stdio(false);
	int t1, t2, t3, t4, t5, t6;
	cin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6;
	cnt[t1]++;
	cnt2[t2]++;
	cnt[t3]++;
	cnt2[t4]++;
	cnt[t5]++;
	cnt2[t6]++;
	for (int i = 0; i <= 1000; i++)
		if (cnt[i] == 1) {
			cout << i << ' ';
			break;
		}
	for (int i = 0; i <= 1000; i++)
		if (cnt2[i] == 1) {
			cout << i << ' ';
			break;
		}
}