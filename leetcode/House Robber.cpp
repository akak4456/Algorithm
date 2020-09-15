class Solution {
public:
    int dp[101];
    int solve(vector<int>&nums,int idx){
       // cout << idx << endl;
        if(idx >= nums.size())
            return 0;
        int& ret = dp[idx];
        if(ret != -1) return ret;
        ret = solve(nums,idx+1);
        ret = max(ret,solve(nums,idx+2)+nums[idx]);
        return ret;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};