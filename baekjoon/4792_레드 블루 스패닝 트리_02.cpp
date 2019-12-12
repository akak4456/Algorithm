//result:틀렸습니다
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 10000 + 1;
int N, M,K;
int arr[MAX];
char adj[MAX][MAX];
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
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> N >> M >> K) {
		if (N == 0)
			break;
		for (int i = 0; i < M; i++) {
			char t;
			int a, b;
			cin >> t >> a >> b;
			adj[a][b] = t;
			adj[b][a] = t;
		}
		priority_queue < pair<long long int, pair<int, int>>>pq;//가중치 start end
		memset(arr, -1, sizeof(arr));
		for (int i = 1; i <= N; i++) {
			for (int j = i+1; j <= N; j++) {
				if (adj[i][j] == 'R') {
					pq.push(make_pair(0, make_pair(i, j)));
				}
				else if (adj[i][j] == 'B') {
					pq.push(make_pair(-1, make_pair(i, j)));
				}
			}
		}
		long long int minBlue = 0;
		while (!pq.empty()) {
			pair<long long int, pair<int, int>> tmp = pq.top();
			pq.pop();
			if (merge(tmp.second.first, tmp.second.second)) {
				minBlue += -tmp.first;
			}
		}
		memset(arr, -1, sizeof(arr));
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (adj[i][j] == 'R') {
					pq.push(make_pair(0, make_pair(i, j)));
				}
				else if (adj[i][j] == 'B') {
					pq.push(make_pair(1, make_pair(i, j)));
				}
			}
		}
		long long int maxBlue = 0;
		while (!pq.empty()) {
			pair<long long int, pair<int, int>> tmp = pq.top();
			pq.pop();
			if (merge(tmp.second.first, tmp.second.second)) {
				maxBlue += tmp.first;
			}
		}
		//cout << minBlue << ' ' << maxBlue << endl;
		if (minBlue <= K && K <= maxBlue)
			cout << "1\n";
		else
			cout << "0\n";
	}
}