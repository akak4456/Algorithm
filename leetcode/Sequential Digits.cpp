class Solution {
public:
    vector<int> ret;
    void solve(int start,int cur,int low,int high){
        if(cur > high||start >= 10){
            return;
        }
        if(cur >= low && cur <= high){
            ret.push_back(cur);
        }
        int newNum = cur*10;
        if(start == 0){
            for(int i=start+1;i<=9;i++){
                newNum += i;
                solve(i,newNum,low,high);
                newNum -= i;
            }
        }else{
            newNum += start+1;
            solve(start+1,newNum,low,high);
            newNum -= start+1;
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        solve(0,0,low,high);
        sort(ret.begin(),ret.end());
        return ret;
    }
};