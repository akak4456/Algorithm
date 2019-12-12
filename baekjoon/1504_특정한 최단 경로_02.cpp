//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int v, e, x, y, z, d1[800],d2[800],d3[800];
vector<vector<pair<int, int>>> vt;
void dijkstra(int start, int d[800]) {
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
		vt[x-1].push_back({ y-1,z });
		vt[y - 1].push_back({ x - 1,z });
	}
	for (int i = 0; i < 800; i++) {
		d1[i] = d2[i] = d3[i] = -1;
	}
	int t1, t2;
	cin >> t1 >> t2;
	t1--;
	t2--;
	dijkstra(0, d1);
	dijkstra(t1, d2);
	dijkstra(t2, d3);
	int sum1 = 0;
	int sum2 = 0;
	if (d1[t1] == -1 || d1[t2] == -1) {
		cout << "-1\n";
	}
	else {
		sum1 += d1[t1];
		if (d2[t2] == -1) {
			sum1 = 987654321;
		}
		else {
			sum1 += d2[t2];
		}
		if (d3[v - 1] == -1) {
			sum1 = 987654321;
		}
		else {
			sum1 += d3[v - 1];
		}
		sum2 += d1[t2];
		if (d3[t1] == -1) {
			sum2 = 987654321;
		}
		else {
			sum2 += d3[t1];
		}
		if (d2[v - 1] == -1) {
			sum2 = 987654321;
		}
		else {
			sum2 += d2[v - 1];
		}
		if (sum1 >= 987654321 && sum2 >= 987654321) {
			cout << "-1\n";
		}
		else {
			cout << min(sum1, sum2) << '\n';
		}
	}
	return 0;
}