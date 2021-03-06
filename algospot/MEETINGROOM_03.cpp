//result:정답
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<vector<int> > adj;
bool disjoint(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second <= b.first || b.second <= a.first;
}

void makeGraph(const vector < pair<int, int> >& meetings) {
	int vars = meetings.size();
	adj.clear(); adj.resize(vars * 2);
	for (int i = 0; i < vars; i += 2) {
		int j = i + 1;
		adj[i * 2 ].push_back(j * 2 + 1);
		adj[j * 2 ].push_back(i * 2 + 1);
		adj[i * 2 + 1].push_back(j * 2);
		adj[j * 2 + 1].push_back(i * 2);
	}
	for (int i = 0; i < vars; i++) {
		for (int j = 0; j < i; j++) {
			if (!disjoint(meetings[i], meetings[j])) {
				adj[i * 2].push_back(j * 2 + 1);
				adj[j * 2].push_back(i * 2 + 1);
			}
		}
	}
}
vector<int> sccId;
vector<int> discovered;
stack<int> st;
int sccCounter, vertexCounter;
int scc(int here) {
	int ret = discovered[here] = vertexCounter++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1)
			ret = min(ret, scc(there));
		else if (sccId[there] == -1)
			ret = min(ret, discovered[there]);
	}
	if (ret == discovered[here]) {
		while (true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if (t == here) break;
		}
		sccCounter++;
	}
	return ret;
}
vector<int> tarjanSCC() {
	sccId = discovered = vector<int>(adj.size(), -1);
	sccCounter = vertexCounter = 0;
	for (int i = 0; i < adj.size(); i++) if (discovered[i] == -1) scc(i);
	return sccId;
}
vector<int> solve2SAT() {
	int n = adj.size() / 2;
	vector<int> label = tarjanSCC();
	for (int i = 0; i < 2 * n; i += 2)
		if (label[i] == label[i + 1])
			return vector<int>();
	vector<int> value(2 * n, -1);
	vector<pair<int, int> > order;
	for (int i = 0; i < 2 * n; i++)
		order.push_back(make_pair(-label[i], i));
	sort(order.begin(), order.end());
	for (int i = 0; i < 2 * n; i++) {
		int vertex = order[i].second;
		int variable = vertex / 2, isTrue = vertex % 2 == 0;
		if (value[variable] != -1) continue;
		value[variable] = !isTrue;
	}
	return value;
}

int main() {
	std::ios::sync_with_stdio(false);
	int c;
	cin >> c;
	while (c--) {
		int n;
		vector<pair<int, int> > input;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			input.push_back(make_pair(t1, t2));
			cin >> t1 >> t2;
			input.push_back(make_pair(t1, t2));
		}
		makeGraph(input);
		vector<int> ans = solve2SAT();
		if (ans.size() == 0) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < ans.size(); i++) {
				//cout << ans[i] << endl;
				if (ans[i] == 1) {
					cout << input[i].first << " " << input[i].second << endl;
				}
			}
		}
	}
}