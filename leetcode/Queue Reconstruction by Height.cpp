class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        for(int i=0;i<people.size();i++){
            cout << people[i][0] << ' ' << people[i][1] << '\n';
        }
        int sz = people.size();
        vector<vector<int>> ret(sz,vector<int>(2,-1));
        for(int i = 0;i<sz;i++){
            int cnt = 0;
            for(int j=0;j<sz;j++){
                if(ret[j][0] == -1||ret[j][0] == people[i][0]){
                    cnt++;
                    if(cnt > people[i][1]){
                        ret[j][0] = people[i][0];
                        ret[j][1] = people[i][1];
                        break;
                    }
                }
            }
        }
        return ret;
    }
};