class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minVal = nums[0]; 
        int maxVal = nums[0]; 
  
        int maxProduct = nums[0]; 
  
        for (int i = 1; i < nums.size(); i++) { 
  
        // When multiplied by -ve number, 
        // maxVal becomes minVal 
        // and minVal becomes maxVal. 
            if (nums[i] < 0) 
                swap(maxVal, minVal); 
  
        // maxVal and minVal stores the 
        // product of subarray ending at arr[i]. 
            maxVal = max(nums[i], maxVal * nums[i]); 
            minVal = min(nums[i], minVal * nums[i]); 
  
        // Max Product of array. 
            maxProduct = max(maxProduct, maxVal); 
        } 
        return maxProduct; 
    }
};