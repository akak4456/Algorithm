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
    int solve(TreeNode* root, vector<int> discover){
        discover.push_back(root->val);
        int sum = 0;
        if(root->left == nullptr&&root->right == nullptr){
            int mul = 1;
            for(int i=discover.size()-1;i>=0;i--){
                sum += discover[i]*mul;
                if(mul < 1000000000)
                    mul*=10;
            }
            return sum;
        }
        if(root->left != nullptr){
            sum += solve(root->left,discover);
        }
        if(root->right != nullptr){
            sum += solve(root->right,discover);
        }
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
            return 0;
        vector<int> tmp;
        return solve(root,tmp);
    }
};