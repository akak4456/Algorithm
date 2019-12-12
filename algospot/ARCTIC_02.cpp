//result:정답
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int C;
int N;
vector<pair<double, double> > points;
double dist[101][101];
bool decision(double d) {
	vector<bool> visited(N, false);
	visited[0] = true;
	queue<int> q;
	q.push(0);
	int seen = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		seen++;
		for (int there = 0; there < N; there++) {
			if (!visited[there] && dist[here][there] <= d) {
				visited[there] = true;
				q.push(there);
			}
		}
	}
	return seen == N;
}
double optimize() {
	double lo = 0,hi=1416;
	for (int it = 0; it < 100; it++) {
		double mid = (lo + hi) / 2.0;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}
int main() {
	std::ios::sync_with_stdio(false);
	cout << fixed;
	cout.precision(2);
	cin >> C;
	while (C--) {
		cin >> N;
		points.clear();
		for (int i = 0; i < N; i++) {
			double x, y;
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
			}
		}
		cout << optimize() << endl;
	}
}