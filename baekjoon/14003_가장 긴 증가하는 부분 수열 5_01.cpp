//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#include <stack>
using namespace std;
const int MAX_N = 1000000;
const int INF = 987654321;
int N;
int lis[MAX_N + 1];
int S[MAX_N + 1];
pair<int, int> arr[MAX_N + 1];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> S[i];
	int plis = 0;
	int pArr = 1;
	lis[0] = S[0];
	arr[0].first = 0;
	arr[0].second = S[0];
	while (pArr < N) {
		if (lis[plis] < S[pArr]) {
			lis[++plis] = S[pArr];
			arr[pArr].first = plis;
			arr[pArr].second = S[pArr];
		}
		else {
			int pos = lower_bound(lis, lis + plis, S[pArr]) - lis;
			lis[pos] = S[pArr];
			arr[pArr].first = pos;
			arr[pArr].second = S[pArr];
		}
		pArr++;
	}
	/*
		수열이 10 20 10 30 25 50 으로 주어질때 arr의 first는 0 1 0 2 1 3으로 주어진다.
		S[5]를 증가부분수열(최장 증가 부분 수열이 아님)의 마지막으로 두었을때 S[5]는 네번째에 위치하게 된다.(idx=3)
		S[4]를 증가부분수열의 마지막으로 두었을때 S[4]는 두번째에 위치하게 된다.(idx=1)
		S[3]를 증가부분수열의 마지막으로 두었을때 S[3]는 세번째에 위치하게 된다.(idx=2)
		S[2]를 증가부분수열의 마지막으로 두었을때 S[2]는 첫번째에 위치하게 된다.(idx=0)
		S[1]를 증가부분수열의 마지막으로 두었을때 S[1]는 두번째에 위치하게 된다.(idx=1)
		S[0]를 증가부분수열의 마지막으로 두었을때 S[0]는 첫번째에 위치하게 된다.(idx=0)
		한편 LIS의 길이가 4임을 알고 있다. S의 마지막 원소부터 조사해보자.
		S[5]는 네번째에 위치하게 된다. 그래서 LIS에 들어갈 수 있다.
		S[4]는 두번째에 위치하게 된다. 근데 아직 LIS의 세번째가 채워지지 않았다. 그러니 들어갈 수 없다.
		S[3]는 세번째에 위치하게 된다. 그래서 LIS에 들어갈 수 있다.
		...이와 같은 원리로 LIS를 구하게 된다.
		즉 arr[i].first는 S[i]를 증가부분수열의 마지막으로 두었을때 S[i]가 위치하게 되는곳을 말하게 된다. 이것은 S[i]를 증가부분수열의 마지막으로 두었을때 (증가부분수열의 길이-1)와 같게 된다.
	*/
	cout << plis + 1 << endl;
	stack<int> s;
	int t = plis;
	for (int k = N - 1; k >= 0; k--) {
		if (t == arr[k].first) {
			s.push(arr[k].second);
			t--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}
