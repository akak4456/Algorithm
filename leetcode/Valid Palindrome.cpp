class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        string convertedString = "";
        for(int i=0;i<s.size();i++){
            if('a' <= s[i] && s[i] <= 'z'){
                convertedString += s[i];
            }else if('A' <= s[i] && s[i] <= 'Z'){
                convertedString += (char)(s[i]+32);
            }else if('0' <= s[i] && s[i] <= '9'){
                convertedString += s[i];
            }
        }
        
        for(int i=0;i<convertedString.size()/2;i++){
            if(convertedString[i] != convertedString[convertedString.size()-1-i])
                return false;
        }
        return true;
    }
};