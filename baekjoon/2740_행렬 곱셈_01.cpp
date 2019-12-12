//result:맞았습니다!!
#include <iostream>
using namespace std;
int A[100][100];
int B[100][100];
int N, M, K;
int R[100][100];
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];
	cin >> M >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				R[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++)
			cout << R[i][j] << ' ';
		cout << '\n';
	}
}