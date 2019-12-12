//result:오답
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct OptimizedDisjointSet {
	vector<int> parent, rank;
	OptimizedDisjointSet(int n) :parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) {
			int tmp = u;
			u = v;
			v = tmp;
		}
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
	}
};
int C;
int N, M;
struct Command {
	string str;
	int u;
	int v;
};
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N >> M;
		OptimizedDisjointSet disjoint(N);
		int idx = -1;
		vector<Command> commands;
		for (int i = 0; i < M; i++) {
			Command tmp;
			cin >> tmp.str >> tmp.u >> tmp.v;
			commands.push_back(tmp);
		}
		for (int i = 0; i < M; i++) {
			Command command = commands[i];
			if (command.str == "ACK") {
				int rankU = disjoint.rank[disjoint.find(command.u)];
				int rankV = disjoint.rank[disjoint.find(command.v)];
				if (rankU != 1&&rankV != 1&&disjoint.find(command.u) != disjoint.find(command.v)) {
					//모순
					idx = i + 1;
					break;
				}
				disjoint.merge(command.u, command.v);
			}
			else if (command.str == "DIS") {
				if (disjoint.find(command.u) == disjoint.find(command.v)) {
					idx = i + 1;
					break;
				}
			}
		}
		if (idx != -1) {
			cout << "CONTRADICTION AT " << idx << endl;
		}
		else {
			vector<int> sz(N, 0);
			for (int i = 0; i < N; i++) {
				//cout << disjoint.parent[i] << " ";
				sz[disjoint.parent[i]]++;
			}
			int maxSz = -1;
			int remain = N;
			for (int i = 0; i < N; i++) {
				//cout << sz[i] << " ";
				if (disjoint.parent[i] == i) {
					maxSz = max(maxSz, sz[i]);
					if(disjoint.rank[i] != 1)
					remain -= sz[i];
				}
			}
			maxSz += remain;
			cout << "MAX PARTY SIZE IS " << maxSz << endl;
		}
	}
}