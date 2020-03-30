//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int D[101];
int N, K;
vector<int> result;
void solve(int n, int k) {
	//cout << n << ' ' << k << endl;
	for (int i = 1; i <= 3; i++) {
		//cout << "D:" << D[n - 1] << endl;
		if (n-i >= 0 && D[n - i] >= k) {
		/*
		인덱스 검사를 안해서 틀렸었음
		*/
			result.push_back(i);
			solve(n - i, k);
			return;
		}
		k -= D[n - i];
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	D[0] = 1;
	D[1] = 1;
	D[2] = 2;
	D[3] = 4;
	for (int i = 4; i <= N; i++) {
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}
	if (K > D[N]) {
		cout << "-1";
	}
	else {
		/*
		vector<string> arr;
		vector<string> arr2;
		for (int nk = 1; nk <= D[N]; nk++) {
			string str = "";
			result.clear();
			solve(N, nk);
			for (int i = 0; i < result.size() - 1; i++) {
				str += result[i] +'0';
				str += '+';
			}
			str += result.back() + '0';
			arr.push_back(str);
		}
		cout << (arr.size() == D[N]) << endl;
		arr2 = arr;
		sort(arr2.begin(), arr2.end());
		for (int i = 0; i < arr.size(); i++) {
			//cout << arr[i] << endl;
			if (arr[i] != arr2[i]) {
				cout << "WRONG\n";
			}
		}
		*/
		solve(N, K);
		for (int i = 0; i < result.size() - 1; i++) {
			cout << result[i] << "+";
		}
		cout << result.back();
	}
}