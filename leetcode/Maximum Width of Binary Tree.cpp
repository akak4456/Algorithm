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
    int minPos[40];
    int maxPos[40];
    void search(TreeNode* here,int curNum,int depth){
        minPos[depth] = min(minPos[depth],curNum);
        maxPos[depth] = max(maxPos[depth],curNum);
        if(curNum <= INT_MAX/2+1){
            if(here->left != nullptr){
                search(here->left,curNum*2,depth+1);
            }
            if(here->right != nullptr){
                search(here->right,curNum*2+1,depth+1);
            }
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        for(int i=0;i<40;i++){
            minPos[i] = INT_MAX;
            maxPos[i] = -1;
        }
        search(root,1,0);
        int ret = -1;
        for(int i=0;i<40;i++){
            cout << minPos[i] << ' ' << maxPos[i] << endl;
            if(maxPos[i] != -1){
                 ret = max(ret,maxPos[i]-minPos[i]);
            }
        }
        return (int)(ret+1);
    }
};