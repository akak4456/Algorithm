class Solution {
public:
    bool allUppercase(string word){
        for(int i=0;i<word.size();i++){
            if(!('A' <= word[i] && word[i] <= 'Z'))
                return false;
        }
        return true;
    }
    bool allLowercase(string word){
        for(int i=0;i<word.size();i++){
            if(!('a' <= word[i] && word[i] <= 'z'))
                return false;
        }
        return true;
    }
    bool firstUppercase(string word){
        if(!('A' <= word[0] && word[0] <= 'Z'))
            return false;
        for(int i=1;i<word.size();i++){
            if(!('a' <= word[i] && word[i] <= 'z'))
                return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if(allUppercase(word))
            return true;
        if(allLowercase(word))
            return true;
        if(firstUppercase(word))
            return true;
        return false;
    }
};