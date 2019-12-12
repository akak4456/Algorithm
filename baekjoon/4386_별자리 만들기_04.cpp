//result:맞았습니다!!
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int MAX = 100 + 1;
int V;
int arr[MAX];
int find(int num) {
	if (arr[num] < 0)
		return num;
	return arr[num] = find(arr[num]);
}
bool merge(int aParent, int bParent) {
	aParent = find(aParent);
	bParent = find(bParent);
	if (aParent == bParent)
		return false;
	arr[aParent] += arr[bParent];
	arr[bParent] = aParent;
	return true;
}
double position[101][2];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V;
	memset(arr, -1, sizeof(arr));
	priority_queue < pair<double, pair<int, int>>>pq;//가중치 start end
	for (int i = 1; i <= V; i++)
		cin >> position[i][0] >> position[i][1];
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			pq.push(make_pair(-sqrt(pow(position[i][0] - position[j][0], 2) + pow(position[i][1] - position[j][1], 2)), make_pair(i, j)));
	double res = 0;
	while (!pq.empty()) {
		pair<double, pair<int, int>> tmp = pq.top();
		pq.pop();
		if (merge(tmp.second.first, tmp.second.second)) {
			res += -tmp.first;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << res << '\n';
}