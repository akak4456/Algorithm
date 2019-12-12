//result:런타임 오류
#include <iostream>
using namespace std;
const int MAXN = 5000000;
unsigned int A[MAXN + 1];
unsigned int newA[MAXN + 1];
int C;
int K, N;
unsigned int q[MAXN*3+1];
unsigned int sum = 0;
int cnt = 0;
int head = 0;
int tail = 0;
int main() {
	std::ios::sync_with_stdio(false);
	
	A[0] = 1983;
	for (int i = 1; i <= MAXN; i++)
		A[i] = (A[i - 1]*214013+2531011) % 4294967296;
	for (int i = 1; i <= MAXN; i++) {
		newA[i] = A[i - 1] % 10000 + 1;
	}
 	cin >> C;
	/*
	A[1] = 1;
	A[2] = 4;
	A[3] = 2;
	A[4] = 1;
	A[5] = 4;
	A[6] = 3;
	A[7] = 1;
	A[8] = 6;
	*/
	while (C--) {
		cin >> K >> N;
		head = 0;
		tail = 0;
		sum = 0;
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			//cout << sum << endl;
			if (sum + newA[i] == K) {
				cnt++;
			}
			else if (sum + newA[i] > K) {
				while (head != tail&&sum + newA[i] > K) {
					sum -= q[head];
					head++;
					if (sum + newA[i] == K) {
						cnt++;
						break;
					}
				}
			}
			sum += newA[i];
			q[tail++] = newA[i];
		}
		cout << cnt << endl;
	}
}