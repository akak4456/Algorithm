//result:틀렸습니다
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 10001;
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
int n;
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
bool ch[MAX_N];
int makeDp(int id,int stat) {
	int& ret = dp[id][stat];
	if (ret != -1)
		return ret;
	if (stat == 1)
		ret = nodes[id]->w;
	else
		ret = 0;
	for (int i = 0; i < nodes[id]->child.size(); i++) {
		int notInclude = makeDp(nodes[id]->child[i]->idx, 0);
		int Include = makeDp(nodes[id]->child[i]->idx, 1);
		if (stat == 1) {
			ret += notInclude;
		}
		else {
			ret += max(notInclude,Include);
		}
	}
	return ret;
}
vector<int> ans;
void ind(int cur) {
	if (dp[cur][0] < dp[cur][1]) {
		ans.push_back(cur);
	}
	for (int i = 0; i < nodes[cur]->child.size(); i++) {
		ind(nodes[cur]->child[i]->idx);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		nodes[i] = new Node;
		nodes[i]->idx = i;
		cin >> nodes[i]->w;
	}
	for (int i = 0; i < n - 1; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		nodes[t1]->adj.push_back(nodes[t2]);
		nodes[t2]->adj.push_back(nodes[t1]);
	}
	root = nodes[1];
	makeTree(root);
	memset(dp, -1, sizeof(dp));
	makeDp(1, 0);
	makeDp(1, 1);
	cout << max(dp[1][0], dp[1][1]) << '\n';
	ind(1);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}