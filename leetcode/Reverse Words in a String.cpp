class Solution {
public:
    string reverseWords(string s) {
        if(s == "")
            return "";
        reverse(s.begin(),s.end());
        while(s[0] == ' '){
            s.erase(0,1);
        }
        if(s == "")
            return "";
        while(s[s.size()-1] == ' '){
            s.erase(s.size()-1,1);
        }
        if(s == "")
            return "";
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '&&s[i+1] == ' '){
                s.erase(i+1,1);
                i--;
            }
        }
        if(s == "")
            return "";
        int start = 0;
        for(int end = 1;end<s.size();end++){
            if(s[end] == ' '){
                reverse(s.begin()+start,s.begin()+end);
                start = end+1;
            }
        }
        reverse(s.begin()+start,s.end());
        return s;
    }
};