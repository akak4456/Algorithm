class Solution {
public:
    int cache[5001][501];
    int solve(int amount,int lastidx,vector<int>& coins){
        if(amount == 0)
            return 1;
        int& ret = cache[amount][lastidx];
        if(ret != -1) return ret;
        ret = 0;
        for(int i=lastidx;i>=0;i--){
            if(amount-coins[i] >= 0)
                ret += solve(amount-coins[i],i,coins);
        }
        return ret;
    }
    int change(int amount, vector<int>& coins) {
        memset(cache,-1,sizeof(cache));
        sort(coins.begin(),coins.end());
        if(coins.empty()){
            if(amount == 0)
                return 1;
            else
                return 0;
        }
        return solve(amount,coins.size()-1,coins);
    }
};