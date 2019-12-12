//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int T;
int n, m, t;
int s, g, h;
int d1[2001], d2[2001], d3[2001];
vector<pair<int,int> > adj[2001];//node value
void dijkstra(int s, int d[2001]) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> >pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		pair<int, int> tmp = pq.top();
		pq.pop();
		if (d[tmp.second] != -1)
			continue;
		d[tmp.second] = tmp.first;
		for (int i = 0; i < adj[tmp.second].size(); i++) {
			int nexT = adj[tmp.second][i].first;
			int cost = tmp.first + adj[tmp.second][i].second;
			if (d[nexT] != -1)
				continue;
			pq.push(make_pair(cost, nexT));
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		for (int i = 0; i <= 2000; i++)
			adj[i].clear();
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back(make_pair(b, d));
			adj[b].push_back(make_pair(a, d));
;		}
		for (int i = 0; i <= 2000; i++) {
			d1[i] = d2[i] = d3[i] = -1;
		}
		vector<int> cand;
		for (int i = 0; i < t; i++) {
			int q;
			cin >> q;
			cand.push_back(q);
		}
		dijkstra(s, d1);
		dijkstra(g, d2);
		dijkstra(h, d3);
		vector<int> result;
		for (int i = 0; i < cand.size(); i++) {
			bool isCan = false;
			if (d1[g] + d2[h] + d3[cand[i]] == d1[cand[i]]) {
				isCan = true;
			}
			if (d1[h] + d3[g] + d2[cand[i]] == d1[cand[i]]) {
				isCan = true;
			}
			if (isCan) {
				result.push_back(cand[i]);
			}
		}
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
	}
}