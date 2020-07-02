class Solution {
public:
    
    int solve(int n,int upperbound){
        //cout << n << ' ' << upperbound<<endl;
        int cnt = n/(upperbound*upperbound);
        n -= cnt * (upperbound*upperbound);
        if(n == 0)
            return cnt;
        int ret = 987654321;
        for(int i=upperbound-1;i>=1;i--){
            if(n-i*i >= 0)
                ret = min(ret,solve(n,i)+cnt);
        }
        return ret;
    }
    int numSquares(int n) {
        int ans = 987654321;
        for(int i=40000;i>=1; i--){
            if(n-i*i >= 0){
                ans = min(ans,solve(n,i));
            }
        }
        return ans;
    }
};