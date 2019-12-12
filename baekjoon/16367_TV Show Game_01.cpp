//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int K, N;
vector<vector<int> > adj;
vector<int> sccId;
vector<int> discovered;

stack<int> st;
int sccCounter, vertexCounter;
/*
void makeGraph(const vector<pair<int, int> >& boolValues) {
	adj.resize(K * 2);
	for (int i = 0; i < boolValues.size(); i++) {
		int f = 0, frev = 0, s = 0, srev = 0;
		if (boolValues[i].first > 0) {
			f = 2 * (boolValues[i].first - 1);
			frev = 2 * (boolValues[i].first - 1) + 1;
		}
		else if (boolValues[i].first < 0) {
			f = 2 * (-boolValues[i].first - 1) + 1;
			frev = 2 * (-boolValues[i].first - 1);
		}
		if (boolValues[i].second > 0) {
			s = 2 * (boolValues[i].second - 1);
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
*/
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
	for (int i = 0; i < 2 * K; i += 2) {
		if (label[i] == label[i + 1])
			return vector<int>();
	}
	vector<int> value(2 * K, -1);
	vector<pair<int, int> > order;
	for (int i = 0; i < 2 * K; i++) {
		order.push_back(make_pair(-label[i], i));
	}
	sort(order.begin(), order.end());
	for (int i = 0; i < 2 * K; i++) {
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
	cin >> K>>N;
	//vector<pair<int, int> > input;
	adj.resize(K *2);
	for (int i = 0; i < N; i++) {
		int lampNum[3];
		char lampColor[3];
		for (int j = 0; j < 3; j++) {
			cin >> lampNum[j] >> lampColor[j];
		}
		for (int p = 0; p < 3; p++) {
			for (int q = 0; q < 3; q++) {
				if (p == q) continue;
				int idx = 2 * (lampNum[p] - 1);
				int idx2 = 2*(lampNum[q]-1);
				if (lampColor[p] == 'R') {
					idx++;
				}
				if (lampColor[q] == 'B') {
					idx2++;
				}
				adj[idx].push_back(idx2);
			}
		}
	}
	//makeGraph(input);
	vector<int> ans = solve2SAT();
	if (ans.empty()) {
		cout << "-1\n";
	}
	else {
		for (int i = 0; i < K; i++) {
			if (ans[i]) {
				cout << 'R';
			}
			else {
				cout << 'B';
			}
		}
		cout << '\n';
	}
}