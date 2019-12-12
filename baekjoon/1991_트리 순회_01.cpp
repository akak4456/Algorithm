//result:맞았습니다!!
#include <iostream>
using namespace std;
struct Node {
	char data;
	Node* parent = NULL;
	Node* left = NULL;
	Node* right = NULL;
};
Node* root;
Node* nodes[26];
int N;
void preorder(Node* node) {
	if (node == NULL)
		return;
	cout << node->data;
	preorder(node->left);
	preorder(node->right);
}
void inorder(Node* node) {
	if (node == NULL)
		return;
	inorder(node->left);
	cout << node->data;
	inorder(node->right);
}
void postorder(Node* node) {
	if (node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	cout << node->data;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		nodes[i] = new Node;
		nodes[i]->data = 'A' + i;
	}
	root = nodes[0];
	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') {
			nodes[b - 'A']->parent = nodes[a - 'A'];
			nodes[a - 'A']->left = nodes[b - 'A'];
		}
		if (c != '.') {
			nodes[c - 'A']->parent = nodes[a - 'A'];
			nodes[a - 'A']->right = nodes[c - 'A'];
		}
	}
	preorder(root);
	cout << '\n';
	inorder(root);
	cout << '\n';
	postorder(root);
	cout << '\n';
}