//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_N = 50000;
int N, M;
vector<int> adj[MAX_N];
int indegree[MAX_N];
priority_queue<int> pq;
int parent[MAX_N];
int Find(int x) {
	if (x == parent[x])
		return x;
	int p = Find(parent[x]);
	parent[x] = p;
	return p;
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
	}
}
vector<pair<int, int> > relation;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int t1, t3;
		char t2;
		cin >> t1 >> t2 >> t3;
		if (t2 == '>') {
			relation.push_back(make_pair(t1, t3));
		}
		else {
			Union(t1, t3);
		}
		
	}
	for (int i = 0; i < N; i++) {
		Find(i);
	}
	for (int i = 0; i < relation.size(); i++) {
		int realX = parent[relation[i].first], realY = parent[relation[i].second];
		adj[realX].push_back(realY);
		indegree[realY]++;
	}
	for (int i = 0; i < N; i++) {
		if (!indegree[i])
			pq.push(-i);
	}
	int cnt = 0;
	while (!pq.empty()) {
		int here = -pq.top();
		cnt++;
		pq.pop();
		//cout << here << ' ';
		for (int i = 0; i < adj[here].size(); i++) {
			int nxt = adj[here][i];
			indegree[nxt]--;
			if (!indegree[nxt])
				pq.push(-nxt);
		}
	}
	if (cnt == N) {
		cout << "consistent\n";
	}
	else {
		cout << "inconsistent\n";
	}
}