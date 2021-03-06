//result:틀렸습니다
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
vector<vector<int> > adj;
vector<int> sccId;
vector<int> discovered;

stack<int> st;
int sccCounter, vertexCounter;
bool sccVisited[500001];

vector<set<int> > sccAdj;
vector<pair<int, bool> > sccComponent;
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
void tarjanSCC() {
	sccId = discovered = vector<int>(adj.size(), -1);
	sccCounter = vertexCounter = 0;
	for (int i = 0; i < adj.size(); i++) if (discovered[i] == -1) scc(i);
	//return sccId;
}
int maxCash = -1;
int S, P;
void findMaxCash(int here,int cost) {
	//cout << here << ' ' << cost << '\n';
	if (sccId[S] != here&&sccComponent[here].second == false) {
		return;
	}
	sccVisited[here] = true;
	cost += sccComponent[here].first;
	if (sccId[S] == here) {
		if (maxCash < cost)
			maxCash = cost;
		return;
	}
	for (int i : sccAdj[here]) {
		if(!sccVisited[i])
		findMaxCash(i, cost);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	adj.resize(N+1);
	for (int i = 0; i < M; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		adj[t1].push_back(t2);
	}
	tarjanSCC();
	sccAdj.resize(sccCounter);
	sccComponent.resize(sccCounter);
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		sccComponent[sccId[i]].first += t;
	}
	cin >> S >> P;
	for (int i = 0; i < P; i++) {
		int t;
		cin >> t;
		sccComponent[sccId[t]].second = true;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int nxt = adj[i][j];
			if (sccId[i] != sccId[nxt]) {
				sccAdj[sccId[i]].insert(sccId[nxt]);
				sccAdj[sccId[nxt]].insert(sccId[i]);
			}
		}
	}
	for (int i = 1; i < sccCounter; i++) {
		//cout << sccAdj[i].size() << '\n';
		//cout << sccComponent[i].first << ' ' << sccComponent[i].second << '\n';
		if (sccComponent[i].second == true) {
			findMaxCash(i, 0);
			break;
		}
		//cout << "done\n";
	}
	cout << maxCash << '\n';
}