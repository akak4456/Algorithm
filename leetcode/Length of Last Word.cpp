class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0;
        bool appear = false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] != ' '){
                appear = true;
                ret++;
            }else if(s[i] == ' '&&appear){
                break;
            }
        }
        return ret;
    }
};