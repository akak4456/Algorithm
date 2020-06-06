class Solution {
public:
    int cache[100][100][100];
    int solve(vector<vector<int>>& costs,int idx,int cntA,int cntB){
        if(idx >= costs.size())
            return 0;
        int& ret = cache[idx][cntA][cntB];
        if(ret != -1) return ret;
        ret = 987654321;
        if(cntA > 0)
            ret = min(ret,solve(costs,idx+1,cntA-1,cntB)+costs[idx][0]);
        if(cntB > 0)
            ret = min(ret,solve(costs,idx+1,cntA,cntB-1)+costs[idx][1]);
        return ret;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(cache,-1,sizeof(cache));
        return solve(costs,0,costs.size()/2,costs.size()/2);
    }
};