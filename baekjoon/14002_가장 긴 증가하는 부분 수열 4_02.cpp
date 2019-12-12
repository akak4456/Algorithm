//result:틀렸습니다
#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
using namespace std;
const int MAX_N = 1000;
const int INF = 987654321;
int N;
int A[MAX_N];
int parent[MAX_N];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(parent, -1, sizeof(parent));
	cin >> N;
	vector<int> vt;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (vt.empty()) {
			vt.push_back(A[i]);
			continue;
		}
		if (vt.back() < A[i]) {
			parent[A[i]] = vt.back();
			vt.push_back(A[i]);
		}
		else {
			auto it = lower_bound(vt.begin(), vt.end(),A[i]);
			*it = A[i];
			if (it != vt.begin()) {
				parent[A[i]] = *(--it);
			}
		}
		/*
		for (int j = 0; j < vt.size(); j++) {
			cout << vt[j] << ' ';
		}
		cout << endl;
		*/
	}
	cout << vt.size() - 1 << '\n';
	vector<int> result;
	int child = vt.back();
	while (child != -1) {
		result.push_back(child);
		child = parent[child];
	}
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << ' ';
	}
	cout << '\n';
}
