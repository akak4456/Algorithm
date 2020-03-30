//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
using namespace std;
void postorder(vector<int> preorder, vector<int> inorder) {
    if (preorder.empty())
        return;
    if (preorder.size() == 1) {
        cout << preorder[0] << ' ';
        return;
    }
    int root = preorder[0];
    int rootIdxInInOrder = 0;
    while (inorder[rootIdxInInOrder] != root)
        rootIdxInInOrder++;
    int leftSize = rootIdxInInOrder;
    int rightSize = inorder.size() - leftSize - 1;
    vector<int> leftPreOrder, leftInOrder;
    vector<int> rightPreOrder, rightInOrder;
    for (int i = 1; i <= leftSize; i++) {
        leftPreOrder.push_back(preorder[i]);
    }
    for (int i = 0; i < leftSize; i++) {
        leftInOrder.push_back(inorder[i]);
    }
    for (int i = leftSize + 1; i < preorder.size(); i++) {
        rightPreOrder.push_back(preorder[i]);
    }
    for (int i = leftSize + 1; i < inorder.size(); i++) {
        rightInOrder.push_back(inorder[i]);
    }
    postorder(leftPreOrder, leftInOrder);
    postorder(rightPreOrder, rightInOrder);
    cout << root << ' ';
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int n;
        vector<int> preorder;
        vector<int> inorder;
        cin >> n;
        preorder.resize(n);
        inorder.resize(n);
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        postorder(preorder, inorder);
        cout << '\n';
    }
}