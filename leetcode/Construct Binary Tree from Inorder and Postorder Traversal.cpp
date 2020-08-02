/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0)
            return nullptr;
        int rootVal = postorder[postorder.size()-1];
        TreeNode* root = new TreeNode();
        root->val = rootVal;
        int inorderIdx = 0,postorderIdx = 0;
        vector<int> leftInorder,leftPostorder;
        while(inorder[inorderIdx] != rootVal){
            leftInorder.push_back(inorder[inorderIdx++]);
            leftPostorder.push_back(postorder[postorderIdx++]);
        }
        inorderIdx++;
        vector<int> rightInorder,rightPostorder;
        while(inorderIdx < inorder.size()){
            rightInorder.push_back(inorder[inorderIdx++]);
            rightPostorder.push_back(postorder[postorderIdx++]);
        }
        root->left = buildTree(leftInorder,leftPostorder);
        root->right = buildTree(rightInorder,rightPostorder);
        return root;
    }
};