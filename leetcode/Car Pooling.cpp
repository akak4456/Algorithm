 bool sortBy(const vector<int>& a,const vector<int>& b){
        return a[1] < b[1];
    }
class Solution {
public:
   
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sort(trips.begin(),trips.end(),sortBy);
        // int start = 0,end = 0;
        // for(int i=0;i<trips.size();i++){
        //     cout << trips[i][0] << ' ' << trips[i][1] << ' ' << trips[i][2] << endl;
        // }
        // for(int i=1;i<=1000;i++){
        //     while(end < trips.size()&&trips[end][1] <= i &&  i <= trips[end][2]){
        //         capacity -= trips[end][0];
        //         end++;
        //     }
        //     while(start < end&&trips[start][2] <= i){
        //         capacity += trips[start][0];
        //         start++;
        //     }
        //     cout << start << ' ' << end << endl;
        //     cout << capacity << endl;
        //     if(capacity < 0)
        //         return false;
        // }
        vector<vector<int>> start[1001];
        vector<vector<int>> end[1001];
        for(int i = 0;i<trips.size();i++){
            start[trips[i][1]].push_back(trips[i]);
            end[trips[i][2]].push_back(trips[i]);
        }
        for(int i=1;i<=1000;i++){
            for(int j=0;j<start[i].size();j++){
                capacity -= start[i][j][0];
            }
            for(int j=0;j<end[i].size();j++){
                capacity += end[i][j][0];
            }
            if(capacity < 0)
                return false;
        }
        return true;
    }
};