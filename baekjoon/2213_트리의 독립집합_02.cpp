//result:맞았습니다!!
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
	if (stat == 1) {
		ret = nodes[id]->w;
		for (int i = 0; i < nodes[id]->child.size(); i++) {
			int nxt = nodes[id]->child[i]->idx;
			ret += makeDp(nxt, 0);
		}
		return ret;
	}
	else {
		ret = 0;
		for (int i = 0; i < nodes[id]->child.size(); i++) {
			int nxt = nodes[id]->child[i]->idx;
			int t1= makeDp(nxt, 0);
			int t2 = makeDp(nxt, 1);
			ret += max(t1,t2);
			if (t1 < t2)
				ch[nxt] = true;
			else
				ch[nxt] = false;
		}
		return ret;
	}
}
vector<int> ans;
void track(int now, bool include) {
	if (include) {
		ans.push_back(now);
		for (int i = 0; i < nodes[now]->child.size(); i++) {
			int nxt = nodes[now]->child[i]->idx;
			track(nxt, false);
		}
	}
	else {
		for (int i = 0; i < nodes[now]->child.size(); i++) {
			int nxt = nodes[now]->child[i]->idx;
			track(nxt, ch[nxt]);
		}
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
	if (dp[1][0] < dp[1][1]) {
		ch[1] = true;
	}
	else {
		ch[1] = false;
	}
	track(1, ch[1]);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}