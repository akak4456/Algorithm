//result:메모리 초과
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
bool visited[MAX];
bool isCan = false;
void dfs(int node,int remain,int visitedCnt) {
	cout << node << ' ' << remain << ' ' << visitedCnt << endl;
	if (remain == 0) {
		if (visitedCnt == N-1) {
			isCan = true;
		}
		return;
	}
	visited[node] = true;
	visitedCnt++;
	for (int i = 1; i <= N; i++) {
		if (i == node)
			continue;
		cout << "next:" << i << endl;
		if (!visited[i]&&adj[node][i] != 0) {
			int aParent = find(node);
			int bParent = find(i);
			if (aParent != bParent) {
				merge(node, i);
				if (adj[node][i] == 'B')
					dfs(i, remain - 1, visitedCnt);
				else
					dfs(i, remain, visitedCnt);
				arr[node] = aParent;
				arr[i] = bParent;
			}
		}
	}
	visited[node] = false;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> N >> M >> K) {
		if (N == 0)
			break;
		memset(arr, -1, sizeof(arr));
		for (int i = 0; i < M; i++) {
			char a;
			int b, c;
			cin >> a >> b >> c;
			adj[b][c] = a;
			adj[c][b] = a;
		}
		dfs(1, K,0);
		if (isCan)
			cout << "1\n";
		else
			cout << "0\n";
	}
}