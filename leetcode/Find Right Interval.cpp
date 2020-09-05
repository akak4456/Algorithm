class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        vector<int> ans = vector<int>(sz,-1);
        vector<pair<pair<int,int>,int>> tmp;
        for(int i=0;i<sz;i++){
            tmp.push_back(make_pair(make_pair(intervals[i][0],intervals[i][1]),i));
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<intervals.size();i++){
            int end = intervals[i][1];
            pair<int,int> p = binarySearch(tmp,end);
            if(p.first >= end){
                ans[i] = p.second;
            }
        }
        return ans;
    }
    pair<int,int> binarySearch(vector<pair<pair<int,int>,int>>& tmp,int target){
        int left = 0,right=tmp.size()-1;
        while(left < right){
            int mid = (left+right)/2;
            if(tmp[mid].first.first < target){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return make_pair(tmp[left].first.first,tmp[left].second);
    }
};