//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> inorder;
vector<int> postorder;
int idx[100001];
int N;
void solve(int inorderBegin, int inorderEnd, int postorderBegin, int postorderEnd) {
	if (inorderBegin > inorderEnd || postorderBegin > postorderEnd)
		return;
	int root = postorder[postorderEnd];
	cout << root << ' ';
	solve(inorderBegin, idx[root] - 1, postorderBegin, postorderBegin + (idx[root]-inorderBegin) - 1);
	solve(idx[root]+1, inorderEnd, postorderBegin+(idx[root] - inorderBegin), postorderEnd-1);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	inorder.resize(N + 1);
	postorder.resize(N + 1);
	for (int i = 0; i < N; i++){
		cin >> inorder[i];
		idx[inorder[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}
	solve(0, N - 1, 0, N - 1);
}