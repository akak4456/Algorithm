//result:메모리 초과
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int data;
	Node* left = NULL;
	Node* right = NULL;
};
int N;
Node* nodes[100001];
Node* root = NULL;
void parse(vector<int> inorder, vector<int> postorder) {
	if (inorder.empty()||postorder.empty())
		return;
	if (root == NULL) {
		root = nodes[postorder.back()];
	}
	vector<int>::iterator it = find(inorder.begin(),inorder.end(),postorder.back());
	vector<int> tmp1, tmp2, tmp3, tmp4;
	for (vector<int>::iterator iter = inorder.begin(); iter != it; iter++) {
		tmp1.push_back(*iter);
	}
	for (vector<int>::iterator iter = it+1; iter != inorder.end(); iter++) {
		tmp3.push_back(*iter);
	}
	for (int i = 0; i < tmp1.size(); i++) {
		tmp2.push_back(postorder[i]);
	}
	for (int i = tmp1.size(); i < postorder.size()-1; i++) {
		tmp4.push_back(postorder[i]);
	}

	//cout << tmp1.size() << ' ' << tmp3.size() << endl;
	if(!tmp2.empty())
	nodes[postorder.back()]->left = nodes[tmp2.back()];
	if(!tmp4.empty())
	nodes[postorder.back()]->right = nodes[tmp4.back()];
	parse(tmp1, tmp2);
	parse(tmp3, tmp4);
}
void preorder(Node* node) {
	if (node == NULL)
		return;
	cout << node->data << ' ';
	preorder(node->left);
	preorder(node->right);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		nodes[i] = new Node;
		nodes[i]->data = i;
	}
	vector<int> tmp1, tmp2;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		tmp1.push_back(t);
	}
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		tmp2.push_back(t);
	}
	parse(tmp1, tmp2);
	preorder(root);
}