//result:오답
#include <iostream>
#include <algorithm>
using namespace std;
int C;
long long int A[100];
long long int B[100];
int cache[101][101];
int n, m;
const long long NEGINF = numeric_limits<long long>::min();
int jlis(int indexA, int indexB) {
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) {
		return ret;
	}
	ret = 2;
	long long int a = (indexA == -1 ? NEGINF : A[indexA]);
	long long int b = (indexB == -1 ? NEGINF : B[indexB]);
	long long int maxElement = max(a, b);

	for (int nextA = indexA + 1; nextA < n; nextA++) {
		if (maxElement < A[nextA]) {
			ret = max(ret, jlis(nextA, indexB) + 1);
		}
	}
	for (int nextB = indexB + 1; nextB < m; nextB++) {
		if (maxElement < B[nextB]) {
			ret = max(ret, jlis(indexA, nextB) + 1);
		}
	}
}
int main() {
	cin >> C;
	while (C--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> B[i];
		}
		cout << jlis(-1, -1) << endl;
	}
}