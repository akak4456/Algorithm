class Solution {
public:
    bool overlap(const vector<int>& interval,const vector<int>& newInterval){
        return interval[0] <= newInterval[1] && interval[1] >= newInterval[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        if(intervals.empty()){
            ret.push_back(newInterval);
            return ret;
        }
        if(newInterval[1] < intervals[0][0]){
            ret.push_back(newInterval);
            for(int i=0;i<intervals.size();i++){
                ret.push_back(intervals[i]);
            }
            return ret;
        }
        if(newInterval[0] > intervals.back()[1]){
            for(int i=0;i<intervals.size();i++){
                ret.push_back(intervals[i]);
            }
            ret.push_back(newInterval);
            return ret;
        }
        for(int i=0;i<intervals.size();i++){
            
            if(!overlap(intervals[i],newInterval)){
                ret.push_back(intervals[i]);
                if(newInterval[0] > intervals[i][1] && newInterval[1] < intervals[i+1][0]){
                    ret.push_back(newInterval);
                }
                continue;
            }
            int start = min(intervals[i][0],newInterval[0]);
            while(i+1 < intervals.size()&&overlap(intervals[i+1],newInterval)){
                i++;

            }
            int end = max(intervals[i][1],newInterval[1]);
            vector<int> tmp;
            tmp.push_back(start);
            tmp.push_back(end);
            ret.push_back(tmp);
        }
        return ret;
    }
};