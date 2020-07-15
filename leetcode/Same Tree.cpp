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
    vector<int> pVal;
    vector<int> qVal;
    void traverse(int what,TreeNode* root){
        if(root == NULL){
            if(what == 0){
                pVal.push_back(-1);
            }else{
                qVal.push_back(-1);
            }
            return;
        }
        if(what == 0){
            pVal.push_back(root->val);
        }else{
            qVal.push_back(root->val);
        }
        traverse(what,root->left);
        traverse(what,root->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverse(0,p);
        traverse(1,q);
        if(pVal.size() != qVal.size())
            return false;
        for(int i=0;i<pVal.size();i++)
            if(pVal[i] != qVal[i])
                return false;
        return true;
    }
};