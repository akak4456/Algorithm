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
    TreeNode* makeTree(vector<int> vec){
        if(vec.empty()){
            return nullptr;
        }
        int root = vec[0];
        vector<int> left,right;
        for(int i=1;i<vec.size();i++){
            if(vec[i] < root){
                left.push_back(vec[i]);
            }else{
                right.push_back(vec[i]);
            }
        }
        TreeNode* rootNode = new TreeNode(root,makeTree(left),makeTree(right));
        return rootNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return makeTree(preorder);
    }
};