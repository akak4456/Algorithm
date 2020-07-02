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
    vector<vector<int>> ans;
    void traverse(TreeNode* root,int depth){
        if(depth > ans.size()){
            vector<int> tmp;
            ans.push_back(tmp);
        }
        ans[depth-1].push_back(root->val);
        if(root->left != nullptr){
            traverse(root->left,depth+1);
        }
        if(root->right != nullptr){
            traverse(root->right,depth+1);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)
            return ans;
        traverse(root,1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};