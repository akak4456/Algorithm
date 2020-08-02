class Solution {
public:
    vector<vector<int>> cache; 
    int solve(vector<int>& prices,int day,int isbuy){
        if(day >= prices.size())
            return 0;
        int& ret = cache[day][isbuy];
        if(ret != -1) return ret;
        ret = solve(prices,day+1,isbuy);//cooldown
        if(isbuy == 0){
            ret = max(ret,solve(prices,day+1,1)-prices[day]);//buy
        }else{
            ret = max(ret,solve(prices,day+2,0)+prices[day]);//sell 
        }
        cout << day << ' ' << ret << endl;
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        else if(prices.size() == 2){
            return max(0,-prices[0]+prices[1]);
        }
        cache = vector<vector<int>>(prices.size(),vector<int>(2,-1));
        return solve(prices,0,0);
    }
};