//result:오답
/*
작은 크기에 대해서 정답이기는 하다.
그러나 큰 수를 곱할 때에는 이와 같이 하면 안된다.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> multiply(const vector<int>& a, const vector<int>& b){
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == 0 && b[j] == 0)
				c[i + j] += 0;
			else
				c[i + j] += 1;
		}
	return c;
}
void addTo(vector<int>& a, const vector<int>& b, int k){
	int length = b.size();
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < length; i++)
		a[i + k] += b[i];
}
void subFrom(vector<int>& a, const vector<int>& b){
	int length = b.size();
	a.resize(max(a.size(), b.size()) + 1);
	for (int i = 0; i < length; i++)
		a[i] -= b[i];
}
vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
	int an = a.size(), bn = b.size();
	if (an < bn)
		return karatsuba(b, a);
	if (an == 0 || bn == 0)
		return vector<int>();
	if (an <= 50)
		return multiply(a, b);
	int half = an / 2;
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	vector<int> result;
	addTo(result, z0, 0);
	addTo(result, z1, half);
	addTo(result, z2, half + half);
	return result;
}
int hugs(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; i++) A[i] = (members[i] != 'M');
	for (int i = 0; i < M; i++) B[M - i - 1] = (fans[i] != 'M');
	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; i++) {
		if (C[i] == N)
			allHugs++;
	}
	return allHugs;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	while (C--) {
		string src1, src2;
		cin >> src1 >> src2;
		cout << hugs(src1, src2) << '\n';
	}
}