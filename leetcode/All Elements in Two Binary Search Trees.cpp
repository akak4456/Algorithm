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
    vector<int> r1,r2;
    void traverse(vector<int>& r,TreeNode* root){
        if(root == nullptr)
            return;
        traverse(r,root->left);
        r.push_back(root->val);
        traverse(r,root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        traverse(r1,root1);
        traverse(r2,root2);
        vector<int> ret;
        int r1Idx = 0,r2Idx = 0;
        while(r1Idx < r1.size()&&r2Idx < r2.size()){
            if(r1[r1Idx] < r2[r2Idx]){
                ret.push_back(r1[r1Idx++]);
            }else{
                ret.push_back(r2[r2Idx++]);
            }
        }
        while(r1Idx < r1.size()){
            ret.push_back(r1[r1Idx++]);
        }
        while(r2Idx < r2.size()){
            ret.push_back(r2[r2Idx++]);
        }
        return ret;
    }
};