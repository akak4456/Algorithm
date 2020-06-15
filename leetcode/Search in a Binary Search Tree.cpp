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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return NULL;
        if(root->val == val)
            return root;
        TreeNode* ret = NULL;
        if(val < root->val){
            TreeNode* tmp = searchBST(root->left,val);
            if(tmp != NULL)
                ret = tmp;
        }
        
        if(val > root->val){
            TreeNode* tmp = searchBST(root->right,val);
            if(tmp != NULL)
                ret = tmp;
        }
            
        return ret;
    }
};