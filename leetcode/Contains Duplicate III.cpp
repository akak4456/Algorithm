class Solution {
public:
    //인덱스 차이(절대값)가 최대 k, 값들 차이(절대값)가 최대 t
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long long int,int>> order;
        for(int i=0;i<nums.size();i++){
            order.push_back(make_pair(nums[i],i));
        }
        sort(order.begin(),order.end());
        int start = 0,end = 1;
        int sz = nums.size();
        for(int i=0;i<order.size();i++){
          //  cout << order[i].first << ' ' << order[i].second << endl;
        }
       // cout << "ABC\n";
        while(start < sz-1 && end < sz){
           // cout << start << ' ' << end << endl;
            if(start == end){
                end++;
                continue;
            }
            if(abs(order[start].first-order[end].first) <= t){
                if(abs(order[start].second-order[end].second) <= k){
                    return true;
                }
                end++;
            }else{
                start++;
            }
        }
        end = sz-1;
        while(start < sz-1){
            if(abs(order[start].first-order[end].first) <= t && abs(order[start].second-order[end].second) <= k){
                return true;
            }
            start++;
        }
        return false;
    }
};