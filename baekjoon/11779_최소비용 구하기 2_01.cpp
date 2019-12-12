//result:틀렸습니다
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;
int v, e, x, y, z, d[1000];
int path[1000];
vector<vector<pair<int, int>>> vt;
void dijkstra(int start, int d[1000]) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	while (pq.size()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (d[here] != -1)
			continue;
		d[here] = cost;
		for (auto it : vt[here]) {
			int next = it.first;
			int acost = -it.second - cost;
			if (d[next] != -1)
				continue;
			path[next] = here;
			pq.push({ acost,next });
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;
	vt.resize(v + 1);
	for (int i = 0; i < e; i++) {
		cin >> x >> y >> z;
		vt[x - 1].push_back({ y - 1,z });
		//vt[y - 1].push_back({ x - 1,z });
	}
	for (int i = 0; i < 1000; i++) {
		d[i] = -1;
	}
	int t1, t2;
	cin >> t1 >> t2;
	t1--;
	t2--;
	dijkstra(t1, d);
	stack<int> route;
	route.push(t2);
	int p = path[t2];
	while (p != t1) {
		route.push(p);
		p = path[p];
	}
	route.push(t1);
	cout << d[t2] << '\n' << route.size() << '\n';
	while (!route.empty()) {
		cout << (route.top()+1) << ' ';
		route.pop();
	}
	cout << '\n';
	return 0;
}