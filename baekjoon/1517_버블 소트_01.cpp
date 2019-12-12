//result:시간 초과
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int key;
	int priority, size;
	Node* left, * right;
	Node(const int& _key) :key(_key), priority(rand()), size(1), left(NULL), right(NULL) {

	}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }

	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if(right)size += right->size;
	}
};
typedef pair<Node*, Node*> NodePair;
NodePair split(Node* root, int key) {
	if (root == NULL) return NodePair(NULL, NULL);
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}

	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}
Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key) {
		root->setLeft(insert(root->left, node));
	}
	else {
		root->setRight(insert(root->right, node));
	}
	return root;
}
int countLessThan(Node* root, int key) {
	if (root == NULL) return 0;
	if (root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
}
const int MAX_N = 500000 + 1;
int N;
int arr[MAX_N];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	long long int cnt = 0;
	Node* root = NULL;
	for (int i = 0; i < N; i++) {
		cnt += i - countLessThan(root, arr[i] + 1);
		root = insert(root, new Node(arr[i]));
	}
	cout << cnt << '\n';
}