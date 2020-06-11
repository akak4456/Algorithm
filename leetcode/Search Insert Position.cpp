class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target <= nums[0])
            return 0;
        if(target > nums.back())
            return nums.size();
        long long int lo = 0,hi = nums.size()-1;
        for(int i=0;i<100;i++){
            long long int mid = (lo+hi)/2;
            cout << mid << endl;
            if(mid-1 >= 0 && target <= nums[mid-1]){
                hi = mid-1;
            }else if(nums[mid] <= target){
                lo = mid+1;
            }
        }
        return (lo+hi)/2;
    }
};