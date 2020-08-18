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
    vector<vector<pair<int,int>>> ans;
    void solve(TreeNode* root, int x,int y){
        if(root == nullptr)
            return;
        ans[x].push_back(make_pair(y,root->val));
        solve(root->left,x-1,y+1);
        solve(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ans = vector<vector<pair<int,int>>>(2000,vector<pair<int,int>>());
        solve(root,1000,0);
        vector<vector<int>> ret;
        for(int i=0;i<2000;i++){
            if(ans[i].empty())
                continue;
            sort(ans[i].begin(),ans[i].end());
            vector<int> tmp;
            for(int t=0;t<ans[i].size();t++){
                tmp.push_back(ans[i][t].second);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};