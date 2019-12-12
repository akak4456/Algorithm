//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C;
int N;
vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {
	const int N = preorder.size();
	if (preorder.empty()) return;
	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	const int R = N - 1 - L;
	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	cout << root << ' ';
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		vector<int> preorder;
		vector<int> inorder;
		int t;
		for (int i = 0; i < N; i++) {
			cin >> t;
			preorder.push_back(t);
		}
		for (int i = 0; i < N; i++) {
			cin >> t;
			inorder.push_back(t);
		}
		printPostOrder(preorder, inorder);
		cout << endl;
	}
}