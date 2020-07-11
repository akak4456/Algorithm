class Solution {
public:
    vector<vector<int>> ans;
    void makeSubset(vector<int>& nums,vector<int> current,int used,int start){
        for(int i=start;i<nums.size();i++){
            if((used & (1<<i)) == 0){
                current.push_back(nums[i]);
                ans.push_back(current);
                makeSubset(nums,current,used+(1<<i),i+1);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        ans.push_back(tmp);
        makeSubset(nums,tmp,0,0);
        return ans;
    }
};