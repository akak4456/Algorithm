class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        int mul = 1;
        for(int i=s.size()-1;i>=0;i--){
            ret += (s[i]-'A'+1)*mul;
            if(mul <= INT_MAX/26){
                mul *= 26;
            }
        }
        return ret;
    }
};