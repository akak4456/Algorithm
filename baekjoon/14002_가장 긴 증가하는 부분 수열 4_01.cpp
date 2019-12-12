//result:틀렸습니다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int INF = 987654321;
int N;
int A[MAX_N];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<int> vt;
	vt.push_back(-INF);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (vt.back() < A[i]) {
			vt.push_back(A[i]);
		}
		else {
			auto it = lower_bound(vt.begin(), vt.end(),A[i]);
			*it = A[i];
		}
	}
	cout << vt.size() - 1 << '\n';
	vector<int> newVt;
	newVt.push_back(vt[1]);
	for (int i = 0; i < N; i++) {
		if (A[i] > newVt.back())
			newVt.push_back(A[i]);
	}
	for (int i = 0; i < newVt.size(); i++)
		cout << newVt[i] << ' ';
	cout << '\n';
}
