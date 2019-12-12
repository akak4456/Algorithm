//result:컴파일 실패
#include <iostream>
#include <vector>
using namespace std;
const int MAX_V = 500;
const int INF = 987654321;
int V;
vector<pair<int, double> > adj[MAX_V];
double prim(vector<pair<int, int> >& selected) {
	selected.clear();
	vector<bool> added(V, false);
	vector<double> minWeight(V, INF);
	vector<int> parent(V,-1);
	double ret = 0;
	minWeight[0] = parent[0] = 0;
	for (int iter = 0; iter < V; iter++) {
		int u = -1;
		for (int v = 0; v < V; v++)
			if (!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
				u = v;
		if (parent[u] != u)
			selected.push_back(make_pair(parent[u], u));
		ret += minWeight[u];
		added[u] = true;
		for (int i = 0; i < V; i++) {
			int v = adj[u][i].first;
			double weight = adj[u][i].second;
			if (!added[v] && minWeight[v] > weight) {
				parent[v] = u;
				minWeight[v] = weight;
			}
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		int M;
		cin >> V >> M;
		for (int i = 0; i < MAX_V; i++) {
			adj[i].clear();
		}
		vector<int> x,y;
		for (int i = 0; i < V; i++) {
			int t;
			cin >> t;
			x.push_back(t);
		}
		for (int i = 0; i < V; i++) {
			int t;
			cin >> t;
			y.push_back(t);
		}
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				adj[i].push_back(make_pair(j, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2))));
			}
		}
		vector<pair<int, int> > sel;
		double ans = prim(sel);
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			ans -= adj[a][b].second;
		}
		cout << ans << endl;
	}
}