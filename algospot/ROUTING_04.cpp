//result:정답
/*
아마도 MAX값에서 잘못되었던 것 같다
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <float.h>
using namespace std;
const int MAX_V = 10000;
int V;
vector<pair<int, double> > adj[MAX_V];
priority_queue<pair<double, int>, vector<pair<double, int> > >pq;
double dijkstra(int src) {
	vector<double> dist(V, DBL_MAX);
	dist[src] = 1;
	pq.push(make_pair(-1, src));
	while (!pq.empty()) {
		double cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			double nextDist = cost * adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist[V - 1];
}
int main() {
	std::ios::sync_with_stdio(false);
	cout << fixed;
	cout.precision(10);
	int c;
	cin >> c;
	while (c--) {
		while (!pq.empty())
			pq.pop();
		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();
		int m;
		cin >> V >> m;
		for (int i = 0; i < m; i++) {
			int t1, t2;
			double t3;
			cin >> t1 >> t2 >> t3;
			adj[t1].push_back(make_pair(t2, t3));
			adj[t2].push_back(make_pair(t1, t3));
		}
		cout << dijkstra(0) << endl;
	}
}