class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        //원소가 가장 많은거
        //두번째로 많은거 선택하고
        //그것의 개수가 조건 만족하면 됨
        if(nums.empty())
            return ret;
        if(nums.size() == 1){
            ret.push_back(nums[0]);
            return ret;
        }
        int n = nums.size();
        int f = 0;
        int s = 0;
        bool fUpdate = false,sUpdate = false;
        int cntf = 0;
        int cnts = 0;
        for(int i=0;i<n;i++){
            if(!fUpdate || f == nums[i]){
                f = nums[i];
                fUpdate = true;
                cntf++;
            }else if(!sUpdate || s == nums[i]){
                s = nums[i];
                sUpdate = true;
                cnts++;
            }else if(cntf == 0){
                f = nums[i];
                cntf = 1;
            }else if(cnts == 0){
                s = nums[i];
                cnts = 1;
            }else{
                cntf--;
                cnts--;
            }
        }
        cntf = 0; cnts = 0;
        for(int i=0;i<n;i++){
            if(fUpdate && nums[i] == f) cntf++;
            if(sUpdate && nums[i] == s) cnts++;
        }
        if(cntf > n/3) ret.push_back(f);
        if(cnts > n/3) ret.push_back(s);
        return ret;
    }
};