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
    int parseInt(const string& src){
        long long int mul = 1;
        int ret = 0;
        for(int i=src.size()-1;i>=0;i--){
            ret += (src[i]-'0')*mul;
            mul *= 2;
        }
        return ret;
    }
    int sum = 0;
    void traverse(TreeNode* root, string src){
        if(root == nullptr){
            return;
        }
        src += (root->val+'0');
        if(root->left == nullptr && root->right == nullptr){
           // cout << src << endl;
            sum += parseInt(src);
            return;
        }
        traverse(root->left,src);
        traverse(root->right,src);
    }
    int sumRootToLeaf(TreeNode* root) {
        traverse(root,"");
        return sum;
    }
};