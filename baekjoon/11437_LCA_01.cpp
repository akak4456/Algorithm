//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 987654321;
struct RMQ {
	int n;
	vector<int> rangeMin;
	RMQ(const vector<int>& array) {
		n = array.size();
		rangeMin.resize(n * 4);
		init(array, 0, n - 1, 1);
	}
	int init(const vector<int>& array, int left, int right, int node) {
		if (left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) return MAX;
		if (left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}
	int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index)
			return rangeMin[node];
		if (nodeLeft == nodeRight) return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = min(
			update(index, newValue, node * 2, nodeLeft, mid),
			update(index, newValue, node * 2 + 1, mid + 1, nodeRight)
		);
	}
	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}
};
int N;
vector<int> child[50001];
int no2serial[50001], serial2no[50001];
int locInTrip[50001], depth[50001];
int nextSerial = 0;
void traverse(int here, int d, vector<int>& trip) {
	no2serial[here] = nextSerial;
	serial2no[nextSerial] = here;
	nextSerial++;
	depth[here] = d;
	locInTrip[here] = trip.size();
	trip.push_back(no2serial[here]);
	for (int i = 0; i < child[here].size(); i++) {
		traverse(child[here][i], d + 1, trip);
		trip.push_back(no2serial[here]);
	}
}
RMQ* prepareRMQ() {
	nextSerial = 0;
	vector<int> trip;
	traverse(0, 0, trip);
	return new RMQ(trip);
}
int getLCA(RMQ* rmq, int u, int v) {
	int lu = locInTrip[u], lv = locInTrip[v];
	if (lu > lv) swap(lu, lv);
	int lca = serial2no[rmq->query(lu, lv)];
	return lca + 1;
}
vector<int> adj[50001];
bool visited[50001];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		t1--;
		t2--;
		//child[t1].push_back(t2);
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		visited[t] = true;
		for (int i = 0; i < adj[t].size(); i++) {
			int nxt = adj[t][i];
			if (!visited[nxt]) {
				visited[nxt] = true;
				child[t].push_back(nxt);
				q.push(nxt);
			}
		}
	}
	int M;
	cin >> M;
	RMQ* rmq = prepareRMQ();
	for (int i = 0; i < M; i++) {
		int q1, q2;
		cin >> q1 >> q2;
		q1--;
		q2--;
		cout << getLCA(rmq, q1, q2) << '\n';
	}
}