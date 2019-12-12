//result:오답
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node {
	int x, y, r,idx;
	int height = 0;
	Node* parent = NULL;
	vector<Node*> child;
};
Node* root;
vector<Node*> nodes;
int C, N;
bool isContain(Node* a, Node* b) {
	double dist = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
	//cout << b->r << " " << a->r << endl;
	return dist < (b->r - a->r);
}
void print() {
	for (int i = 0; i < N; i++) {
		cout << nodes[i]->idx;
		if (nodes[i]->parent != NULL)
			cout << " parent:" << nodes[i]->parent->idx;
		for (int j = 0; j < nodes[i]->child.size(); j++) {
			cout << " child:"<<nodes[i]->child[j]->idx;
		}
		cout << endl;
	}
}
int height(Node* root) {
	vector<int> heights;
	for (int i = 0; i < root->child.size(); i++)
		heights.push_back(height(root->child[i]));
	if (heights.empty()) {
		return 0;
	}
	for (int i = 0; i < heights.size(); i++)
		root->height = max(root->height, heights[i] + 1);
	//cout << root->idx<<" "<<root->height << endl;
	return root->height;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		root = NULL;
		nodes.clear();
		for (int i = 0; i < N; i++) {
			Node* tmp = new Node;
			cin >> tmp->x >> tmp->y >> tmp->r;
			tmp->idx = i;
			nodes.push_back(tmp);
			if (i == 0)
				root = tmp;
		}
		for (int i = 1; i < N; i++) {
			int minR = 987654321;
			int minIdx = -1;
			for(int j=0;j<N;j++){
				if (isContain(nodes[i], nodes[j])) {
					if (nodes[j]->r < minR) {
						minR = nodes[j]->r;
						minIdx = j;
					}
				}
			}
			//cout << i << " " << minIdx << endl;
			nodes[i]->parent = nodes[minIdx];
			nodes[minIdx]->child.push_back(nodes[i]);
			//nodes[minIdx]->height = max(nodes[minIdx]->height, nodes[i]->height+1);
			//cout << nodes[minIdx]->height << endl;
		}
		//print();
		height(root);
		vector<int> ans;
		for (int i = 0; i < root->child.size(); i++)
			ans.push_back(root->child[i]->height);
		sort(ans.begin(), ans.end());
		int sum = ans.back() +1;
		ans.pop_back();
		if (ans.size() > 0) {
			sum += ans.back() + 1;
		}
		cout << sum << endl;
		for (int i = 0; i < N; i++) {
			delete nodes[i];
		}
	}
}