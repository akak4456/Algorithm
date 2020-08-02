class Solution {
public:
    int findMin(vector<int>& nums) {
        int minVal = nums[0];
        for(int i=1;i<nums.size();i++){
            minVal = min(minVal,nums[i]);
        }
        return minVal;
    }
};