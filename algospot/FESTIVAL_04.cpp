//result:정답
#include <cstdio>
#include <iostream>
#include <limits.h>
using namespace std;

int C;
int N, L;
int A[1001];
int main() {
	cin >> C;
	while (C--) {
		scanf("%d%d", &N, &L);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
		}
		double MIN = INT_MAX;
		for (int i = L; i <= N; i++) {
			double sum = 0;
			for (int j = 1; j <= i; j++) {
				sum += A[j];
			}
			if (MIN > sum / i) {
				MIN = sum / i;
			}
			for (int j = 1; i + j <= N; j++) {
				sum -= A[j];
				sum += A[i+j];
				if (MIN > sum / i) {
					MIN = sum / i;
				}
			}
		}
		printf("%.11f\n", MIN);
	}
	cin >> N;
}