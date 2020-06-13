class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()){
            vector<int> tmp;
            return tmp;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector <int> divCount(n, 1); 
        vector <int> prev(n, -1); 
        int max_ind = 0; 
        for (int i=1; i<n; i++) { 
            for (int j=0; j<i; j++) { 
                if (nums[i]%nums[j] == 0){ 
                    if (divCount[i] < divCount[j] + 1){ 
                        divCount[i] = divCount[j]+1; 
                        prev[i] = j; 
                    } 
                } 
            } 
            if (divCount[max_ind] < divCount[i]) 
                max_ind = i; 
        } 
        int k = max_ind; 
        vector<int> best;
        while (k >= 0) { 
            best.push_back(nums[k]);
            k = prev[k]; 
        } 
        sort(best.begin(),best.end());
        return best;
    }
};