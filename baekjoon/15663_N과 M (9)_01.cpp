//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 8;
int N, M;
int arr[MAXN + 2];
bool check[MAXN + 2];
vector<int> print_v;
void go(int cnt) {
	if (cnt == M) {
		for (int i = 0; i <(int) print_v.size(); ++i) {
			cout << print_v[i] << " ";
		}
		cout << '\n';
		return;
	}
	bool used[10002] = { false, };
	for (int i = 0; i < N ; ++i) {
		if (!used[arr[i]] && !check[i]) {
			check[i] = true;
			used[arr[i]] = true;
			print_v.push_back(arr[i]);
			go(cnt + 1);
			print_v.pop_back();
			check[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) cin >> arr[i];

	sort(arr, arr + N);
	go(0);
	
	return 0;
}
[출처] [백준]-15663번 N과 M(9)|작성자 예령