class Solution {
public:
    int cnt = 0;
    string exist[26];
    bool wordPattern(string pattern, string str) {
        for(int i=0;i<26;i++){
            exist[i] = "!";
        }
        vector<string> sVec;
        int startIdx = 0;
        for(int i=1;i<str.size();i++){
            if(str[i] == ' '){
                sVec.push_back(str.substr(startIdx,i-startIdx));
                startIdx = i+1;
            }
        }
        sVec.push_back(str.substr(startIdx,str.size()-startIdx));
        if(sVec.size() != pattern.size())
            return false;
        for(int i=0;i<sVec.size();i++){
            cout << sVec[i] << endl;
            int patternIdx = pattern[i] - 'a';
           // cout << exist[patternIdx] << endl;
            if(exist[patternIdx] == "!"){
                cnt++;
                exist[patternIdx] = sVec[i];
            }else if(exist[patternIdx] != sVec[i]){
                return false;
            }
        }
        set<string> strSet;
        for(int i=0;i<26;i++){
            if(exist[i] != "!"){
                strSet.insert(exist[i]);
            }
        }
        return strSet.size() == cnt;
    }
};