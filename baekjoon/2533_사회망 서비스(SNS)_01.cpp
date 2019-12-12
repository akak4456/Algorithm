//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 1000001;
struct Node {
	int idx;
	int w;
	Node* parent = NULL;
	vector<Node*> adj;
	vector<Node*> child;
	bool visited = false;
};
Node* nodes[MAX_N];
Node* root;
int N;
int dp[MAX_N][2];
void makeTree(Node* node) {
	node->visited = true;
	for (int i = 0; i < node->adj.size(); i++) {
		Node* next = node->adj[i];
		if (next->visited == false) {
			next->visited = true;
			next->parent = node;
			node->child.push_back(next);
			makeTree(next);
		}
	}
}
int makeDp(int cur,int stat) {
	int& ret = dp[cur][stat];
	if (ret != -1)
		return ret;
	if (stat == 1) {
		ret = 1;
		for (int i = 0; i < nodes[cur]->child.size(); i++) {
			int nxt = nodes[cur]->child[i]->idx;
			ret += min(makeDp(nxt, 1), makeDp(nxt, 0));
		}
	}
	else {
		ret = 0;
		for (int i = 0; i < nodes[cur]->child.size(); i++) {
			int nxt = nodes[cur]->child[i]->idx;
			ret += makeDp(nxt, 1);
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		nodes[i] = new Node;
		nodes[i]->idx = i;
	}
	for (int i = 0; i < N - 1; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		nodes[t1]->adj.push_back(nodes[t2]);
		nodes[t2]->adj.push_back(nodes[t1]);
	}
	root = nodes[1];
	makeTree(root);
	memset(dp, -1, sizeof(dp));
	makeDp(1,0);
	makeDp(1, 1);
	cout << min(dp[1][0], dp[1][1]) << '\n';
}