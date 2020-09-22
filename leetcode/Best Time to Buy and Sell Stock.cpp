class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int ret = 0;
        int last = 987654321;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < last){
                last = prices[i];
            }else{
                ret = max(ret,prices[i]-last);
            }
        }
        return ret;
    }
};