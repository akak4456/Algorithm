//result:맞았습니다!!
#include <iostream>
using namespace std;
int N;
long long int B;
int A[5][5];
int bin[100];
const int MOD = 1000;
void dectobin(long long int dec) {
	int idx = 0;
	long long int d = dec;
	bin[idx++] = d % 2;
	while (d / 2 > 0) {
		d /= 2;
		bin[idx++] = d % 2;
	}
}
int R[100][5][5];//idx i j
void matrixProduct(int a1[5][5], int a2[5][5], int ret[5][5]) {
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			ret[i][k] = 0;
			for (int j = 0; j < N; j++) {
				ret[i][k] += a1[i][j] * a2[j][k];
				ret[i][k] %= MOD;
			}
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	dectobin(B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			R[0][i][j] = A[i][j] % MOD;
		}
	}
	for (int i = 1; i < 100; i++) {
		matrixProduct(R[i - 1], R[i - 1], R[i]);
	}
	int ans[5][5];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				ans[i][j] = 1;
			else
				ans[i][j] = 0;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (bin[i] == 1) {
			/*
			for (int i1 = 0; i1 < N; i1++) {
				for (int j1 = 0; j1 < N; j1++) {
					cout << R[i][i1][j1] << ' ';
				}
				cout << '\n';
			}
			*/
			int newAns[5][5];
			matrixProduct(ans, R[i], newAns);
			for (int y = 0; y < N; y++)
				for (int x = 0; x < N; x++)
					ans[y][x] = newAns[y][x];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}