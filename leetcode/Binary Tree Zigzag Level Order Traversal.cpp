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
    vector<vector<int>> result;
    void solve(TreeNode* root,int level){
        if(root == nullptr)
            return;
        if(result.size() < level+1){
            vector<int> tmp;
            result.push_back(tmp);
        }
        result[level].push_back(root->val);
        solve(root->left,level+1);
        solve(root->right,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root,0);
        for(int i=0;i<result.size();i++){
            if(i%2 == 1){
                reverse(result[i].begin(),result[i].end());
            }
        }
        return result;
    }
};