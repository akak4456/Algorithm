class Solution {
public:
    vector<vector<int> > cache;
    int solve(int start,int end){
       // cout << start << ' ' << end << '\n';
        if(start == end)
            return 1;
        int& ret = cache[start][end];
        if(ret != -1) return ret;
        int m1 = 0,m2 = 0;
        ret = 0;
        for(int i = start; i<= end; i++){
            if(i-1 >= start)
                m1 = solve(start,i-1);
            if(i+1 <= end)
                m2 = solve(i+1,end);
            if(m1 == 0)
                ret += m2;
            else if(m2 == 0)
                ret += m1;
            else
                ret += m1*m2;
           // cout << m1 << ' ' << m2 << endl;
           // cout << "RET:" << ret << endl;
        }
        
        return ret;
    }
    int numTrees(int n) {
        cache = vector<vector<int> >(n+1,vector<int>(n+1,-1));
        return solve(1,n);
    }
};