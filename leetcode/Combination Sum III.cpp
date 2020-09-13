class Solution {
public:
    vector<vector<int>> ret;
    void solve(int k,int n,vector<int> src,int sum,int start){
        if(src.size() == k){
            if(sum == n){
                ret.push_back(src);
            }
            return;
        }
        for(int i=start;i<=9;i++){
            src.push_back(i);
            sum += i;
            solve(k,n,src,sum,i+1);
            src.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        solve(k,n,tmp,0,1);
        return ret;
    }
};