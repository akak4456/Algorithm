class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty())
            return true;
        if(t.empty())
            return false;
        int sidx = 0,tidx=0;
        while(tidx < t.size()){
            if(s[sidx] == t[tidx]){
                sidx++;
                if(sidx == s.size())
                    return true;
            }
            tidx++;
        }
        return false;
    }
};