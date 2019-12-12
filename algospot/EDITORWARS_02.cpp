//result:정답
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct BipartiteUnionFind {
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) :parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v) {
		if (u == -1 || v == -1) return max(u, v);
		u = find(u); v = find(v);
		if (u == v) return u;
		if (rank[u] > rank[v]) {
			int tmp = u;
			u = v;
			v = tmp;
		}
		parent[u] = v;
		size[v] += size[u];
		if (rank[u] == rank[v])rank[v]++;
		return v;
	}
	bool dis(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b; enemy[b] = a;
		return true;
	}
	bool ack(int u, int v) {
		u = find(u); v = find(v);
		if (enemy[u] == v) return false;
		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		if (b != -1) enemy[b] = a;
		return true;
	}
};
int C;
int N, M;
int maxParty(const BipartiteUnionFind& buf) {
	int ret = 0;
	for (int node = 0; node < N; node++) {
		if (buf.parent[node] == node) {
			int enemy = buf.enemy[node];
			if (enemy > node) continue;
			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}
struct Command {
	string str;
	int u, v;
};
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N >> M;
		BipartiteUnionFind disjoint(N);
		int idx = -1;
		vector<Command> commands;
		for (int i = 0; i < M; i++) {
			Command tmp;
			cin >> tmp.str >> tmp.u >> tmp.v;
			commands.push_back(tmp);
		}
		for (int i = 0; i < M; i++) {
			Command command = commands[i];
			if (command.str == "ACK"&&!disjoint.ack(command.u,command.v)) {
				idx = i + 1;
				break;
			}
			else if (command.str == "DIS" && !disjoint.dis(command.u, command.v)) {
				idx = i + 1;
				break;
			}
		}
		if (idx != -1) {
			cout << "CONTRADICTION AT " << idx << endl;
		}
		else {
			cout << "MAX PARTY SIZE IS " << maxParty(disjoint) << endl;
		}
	}
}