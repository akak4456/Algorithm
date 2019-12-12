//result:런타임 오류
#include <iostream>
using namespace std;
int C;
int N;
struct Node {
	int data;
	Node* left = NULL;
	Node* right = NULL;
};
void postOrder(Node* n) {
	if (n->left != NULL) {
		postOrder(n->left);
	}
	if (n->right != NULL) {
		postOrder(n->right);
	}
	cout << n->data << " ";
}
Node* findNode(Node* n,int t) {
	if (n->data == t) {
		return n;
	}
	Node* ret = NULL;
	if (n->left != NULL) {
		Node* ans = findNode(n->left, t);
		if (ans != NULL)
			ret = ans;
	}
	if (n->right != NULL) {
		Node* ans = findNode(n->right, t);
		if (ans != NULL)
			ret = ans;
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		Node* completeRoot = NULL;
		Node* notCompleteRoot = NULL;
		for (int i = 0; i < N; i++) {
			Node* tmp = new Node;
			cin >> tmp->data;
			if (i == 0) {
				completeRoot = tmp;
			}
			else {
				Node* leftGo = completeRoot;
				while (leftGo->left != NULL) {
					leftGo = leftGo->left;
				}
				leftGo->left = tmp;
			}
		}
		int t;
		cin >> t;
		Node* next = completeRoot;
		while (next->data != t) {
			next = next->left;
		}
		notCompleteRoot = next->left;
		next->left = NULL;
		Node* nextPoint = next;
		for (int i = 1; i < N; i++) {
			cin >> t;
			Node* tmp = findNode(completeRoot, t);
			if (tmp != NULL) {
				nextPoint = tmp;
			}
			else {
				Node* tmp2 = nextPoint;
				tmp = findNode(notCompleteRoot, t);
				tmp2->right = notCompleteRoot;
				notCompleteRoot = tmp->left;
				tmp->left = NULL;
			}
		}
		postOrder(completeRoot);
		cout << endl;
	}
}