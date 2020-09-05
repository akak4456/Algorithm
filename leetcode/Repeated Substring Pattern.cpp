class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() <= 1)
            return false;
        for(int cap = 2;cap <= s.size();cap++){
            if(s.size()%cap != 0)
                continue;
            int step = s.size()/cap;
            string origin = s.substr(0,step);
            bool isCan = true;
            for(int i=step;i<s.size();i+=step){
                if(origin != s.substr(i,step)){
                    isCan = false;
                    break;
                }
            }
            if(isCan)
                return true;
        }
        return false;
    }
};