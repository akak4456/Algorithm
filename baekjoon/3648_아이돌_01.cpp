//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N, M;
vector<vector<int> > adj;
vector<int> sccId;
vector<int> discovered;

stack<int> st;
int sccCounter, vertexCounter;
void makeGraph(const vector<pair<int, int> >& boolValues) {
	adj.resize(N * 2);
	for (int i = 0; i < boolValues.size(); i++) {
		int f=0, frev=0, s=0, srev=0;
		if (boolValues[i].first > 0) {
			f = 2 * (boolValues[i].first-1);
			frev = 2 * (boolValues[i].first - 1) + 1;
		}
		else if (boolValues[i].first < 0) {
			f = 2 * (-boolValues[i].first - 1) + 1;
			frev = 2 * (-boolValues[i].first - 1);
		}
		if (boolValues[i].second > 0) {
			s = 2 * (boolValues[i].second-1);
			srev = 2 * (boolValues[i].second - 1) + 1;
		}
		else if (boolValues[i].second < 0) {
			s = 2 * (-boolValues[i].second - 1) + 1;
			srev = 2 * (-boolValues[i].second - 1);
		}
		adj[frev].push_back(s);
		adj[srev].push_back(f);
	}
}
int scc(int here) {
	int ret = discovered[here] = vertexCounter++;
	st.push(here);
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (discovered[there] == -1) {
			ret = min(ret, scc(there));
		}
		else if (sccId[there] == -1) {
			ret = min(ret, discovered[there]);
		}
	}
	if (ret == discovered[here]) {
		while (true) {
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if (t == here) break;
		}
		++sccCounter;
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
	vector<int> label = tarjanSCC();
	for (int i = 0; i < 2 * N; i += 2) {
		if (label[i] == label[i + 1])
			return vector<int>();
	}
	vector<int> value(2 * N, -1);
	vector<pair<int, int> > order;
	for (int i = 0; i < 2 * N; i++) {
		order.push_back(make_pair(-label[i], i));
	}
	sort(order.begin(), order.end());
	for (int i = 0; i < 2 * N; i++) {
		int vertex = order[i].second;
		int variable = vertex / 2;
		if (value[variable] != -1) continue;
		if (vertex % 2 == 0) {
			value[variable] = 0;
		}
		else {
			value[variable] = 1;
		}
	}
	return value;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin >> N >> M) {
		while (!st.empty())
			st.pop();
		adj.clear();
		vector<pair<int, int> > input;
		for (int i = 0; i < M; i++) {
			int t1, t2;
			cin >> t1 >> t2;
			input.push_back(make_pair(t1, t2));
		}
		input.push_back(make_pair(1, 1));
		makeGraph(input);
		vector<int> ans = solve2SAT();
		if (ans.empty()) {
			cout << "no\n";
		}
		else {
			cout << "yes\n";
		}
	}
}