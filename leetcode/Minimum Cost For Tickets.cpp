class Solution {
public:
    int cache[400];
    int solve(vector<int>& days, vector<int>& costs, int idx){
        if(idx == days.size())
            return 0;
        int& ret = cache[idx];
        if(ret != -1) return ret;
        ret = solve(days,costs,idx+1)+costs[0];
        int nxt = idx+1;
        while(nxt < days.size()&&days[nxt]-days[idx] < 7){
            nxt++;
        }
        ret = min(ret,solve(days,costs,nxt)+costs[1]);
        nxt = idx+1;
        while(nxt < days.size()&&days[nxt]-days[idx] < 30){
            nxt++;
        }
        ret = min(ret,solve(days,costs,nxt)+costs[2]);
        return ret;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(cache,-1,sizeof(cache));
        return solve(days,costs,0);
    }
};