class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1)
            return 1;
        sort(s.begin(),s.end());
        int ret = 0;
        for(int i=0;i<s.size()-1;i++){
           // cout << i << endl;
            if(s[i] == s[i+1]){
                s.erase(s.begin()+i);
                s.erase(s.begin()+i);
                ret += 2;
                i--;
            }
            if(s.empty())
                break;
            //cout << s << endl;
        }
        if(s.size() >= 1)
            ret++;
        return ret;
    }
};