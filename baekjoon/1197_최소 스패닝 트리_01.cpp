//result:맞았습니다!!
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 10000 + 1;
int V, E;
int arr[MAX];
int find(int num) {
	if (arr[num] < 0)
		return num;
	return arr[num] = find(arr[num]);
}
bool merge(int aParent, int bParent){
	aParent = find(aParent);
	bParent = find(bParent);
	if (aParent == bParent)
		return false;
	arr[aParent] += arr[bParent];
	arr[bParent] = aParent;
	return true;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	memset(arr, -1, sizeof(arr));
	priority_queue < pair<long long int, pair<int, int>>>pq;//가중치 start end
	for (int i = 0; i < E; i++) {
		int a, b;
		long long int d;
		cin >> a >> b >> d;
		pq.push(make_pair(-d, make_pair(a, b)));
	}
	long long int res = 0;
	while (!pq.empty()) {
		pair<long long int, pair<int, int>> tmp = pq.top();
		pq.pop();
		if (merge(tmp.second.first, tmp.second.second)) {
			res += -tmp.first;
		}
	}
	cout << res << '\n';
}