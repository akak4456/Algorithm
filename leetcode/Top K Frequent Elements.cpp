/*
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
이것은
O(n log n)보다 좋거나 최소한 이 시간 정도 되는 알고리즘 그러니까 '이하' 정도로 생각하는 게 낫다
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mapping;
        int maxFreq = -1;
        for(int i=0;i<nums.size();i++){
            map<int,int>::iterator it = mapping.find(nums[i]);
            if(it == mapping.end()){
                mapping.insert(make_pair(nums[i],1));
                maxFreq = max(maxFreq,1);
            }else{
                it->second++;
                maxFreq = max(maxFreq,it->second);
            }
        }
        vector<int> bucketSort[maxFreq+1];
        for(map<int,int>::iterator it = mapping.begin();it!=mapping.end();it++){
            bucketSort[it->second].push_back(it->first);
        }
        vector<int> ans;
        for(int i=maxFreq;i >= 0;i--){
            for(int t=0;t<bucketSort[i].size();t++){
                ans.push_back(bucketSort[i][t]);
                k--;
                if(k == 0)
                    break;
            }
            if(k == 0)
                break;
        }
        return ans;
    }
};