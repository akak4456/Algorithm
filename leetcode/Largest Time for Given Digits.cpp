class Solution {
public:
    string largest = "00:00";
    bool finish = false;
    void solve(vector<int>& A,int used,vector<char> src){
        if(src.size() == 4){
            string hour = "";
            hour += src[0];
            hour += src[1];
            string minute = "";
            minute += src[2];
            minute += src[3];
            if(hour >= "24" || minute >= "60")
                return;
            finish = true;
            string result = hour + ":" + minute;
            largest = max(largest,result);
            return;
        }
        for(int i=0;i<4;i++){
            if((used&(1<<i)) == 0){
                src.push_back((char)(A[i]+'0'));
                solve(A,used+(1<<i),src);
                src.pop_back();
            }
        }
    }
    string largestTimeFromDigits(vector<int>& A) {
        vector<char> tmp;
        solve(A,0,tmp);
        if(!finish)
            return "";
        return largest;
    }
};