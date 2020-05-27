class Solution {
public:
    int dp[500][500];
    int solve(vector<int>& A, vector<int>& B, int i,int j){
        if(i >= A.size() || j >= B.size())
            return 0;
        int& ret = dp[i][j];
        if(ret != -1) return ret;
        ret = solve(A,B,i+1,j);
        int idx = -1;
        for(int t=j;t<B.size();t++){
            if(A[i] == B[t]){
                idx = t;
                break;
            }
        }
        if(idx != -1)
            ret = max(ret,solve(A,B,i+1,idx+1)+1);
        return ret;
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memset(dp,-1,sizeof(dp));
        return solve(A,B,0,0);
    }
};