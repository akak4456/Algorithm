class Solution {
public:
    int minLen = INT_MAX, maxLen = INT_MIN;
    int len_s = 0;
    void buildPath(string &s, vector<string> &res, string cur, unordered_set<string> &dict, vector<int>& isBreakable, int pos){
        //We use minLen and maxLen to shrink the searching range
        for(int i = minLen; i <= min(maxLen, len_s - pos); i++){
            if(isBreakable[i + pos]==1 && dict.count(s.substr(pos, i))!=0){
                if(i + pos == len_s) res.push_back(cur + s.substr(pos, i));
                else buildPath(s, res, cur + s.substr(pos, i) + " ", dict, isBreakable, i+pos);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        if(wordDict.empty()) return res;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        len_s = s.size();
        vector<int> isBreakable(len_s+1, 0);
        //Cut from the last of the string, which is comparing empty string, always be 1
        isBreakable[len_s] = 1;
        //Note the word.size() returns an usigned int
        for(string word: wordDict){
            minLen = minLen > static_cast<int>(word.size()) ? word.size() : minLen;
            maxLen = maxLen < static_cast<int>(word.size()) ? word.size() : maxLen;
        }

        for(int i = len_s - minLen; i >= 0; i--){
            for(int j = minLen; j <= min(maxLen, len_s - i); j++){
                if(isBreakable[j+ i] == 1 && dict.count(s.substr(i, j))!=0){
                    isBreakable[i] = 1;
                    break;
                }
            }
        }
        if(isBreakable[0])
            buildPath(s, res, "", dict, isBreakable, 0);
        
        return res;
        
    }
};