class Solution {
public:
    vector<vector<vector<int>>> cache;
    int solve(vector<int>& prices,int day, int isbuy,int transactioncnt){
       // cout << day << ' ' << isbuy << ' ' << transactioncnt << endl;
        if(day == prices.size())
            return 0;
        if(transactioncnt == 4)
            return 0;
        int& ret = cache[day][isbuy][transactioncnt];
        if(ret != -1)return ret;
        ret = solve(prices,day+1,isbuy,transactioncnt);
        if(isbuy == 0){
            //buy
            ret = max(ret,solve(prices,day+1,1,transactioncnt+1)-prices[day]);
        }else if(isbuy == 1){
            //sell
            ret = max(ret,solve(prices,day+1,0,transactioncnt+1)+prices[day]);
        }
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        cache = vector<vector<vector<int>>>(prices.size(),vector<vector<int>>(2,vector<int>(5,-1)));
        return max(solve(prices,0,0,0),solve(prices,0,1,1)-prices[0]);
    }
};