//result:맞았습니다!!
#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int idx;
	int sz = 1;
	Node* parent = NULL;
	vector<Node*> adj;
	bool visited = false;
};
Node* nodes[100001];
Node* root;
int N, R, Q;
void makeTree(Node* node) {
	node->visited = true;
	for (int i = 0; i < node->adj.size(); i++) {
		Node* next = node->adj[i];
		if (next->visited == false) {
			next->visited = true;
			next->parent = node;
			makeTree(next);
			node->sz += next->sz;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> R >> Q;
	for (int i = 1; i <= N; i++) {
		nodes[i] = new Node;
		nodes[i]->idx = i;
	}
	root = nodes[R];
	for (int i = 0; i < N-1; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		nodes[t1]->adj.push_back(nodes[t2]);
		nodes[t2]->adj.push_back(nodes[t1]);
	}
	makeTree(root);
	for (int i = 0; i < Q; i++) {
		int t;
		cin >> t;
		cout << nodes[t]->sz << '\n';
	}
}