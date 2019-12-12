//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N = 32000 + 1;
int N, M;
vector<int> adj[MAX_N];
int indegree[MAX_N];
priority_queue<int> pq;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		adj[t1].push_back(t2);
		indegree[t2]++;
	}
	for (int i = 1; i <= N; i++) {
		if (!indegree[i])
			pq.push(-i);
	}
	while (!pq.empty()) {
		int here = -pq.top();
		pq.pop();
		cout << here << ' ';
		for (int i = 0; i < adj[here].size(); i++) {
			int nxt = adj[here][i];
			indegree[nxt]--;
			if (!indegree[nxt])
				pq.push(-nxt);
		}
	}
}