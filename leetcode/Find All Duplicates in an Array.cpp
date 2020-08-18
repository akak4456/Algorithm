class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        nums.push_back(10);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[abs(nums[i])] >= 0){
                //first occur
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            }else{
                //second occur
                ret.push_back(abs(nums[i]));
            }
        }
        return ret;
    }
};