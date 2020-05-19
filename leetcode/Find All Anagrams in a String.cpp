class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pcnt[26];
        int scnt[26];
        for(int i=0;i<26;i++){
            pcnt[i] = scnt[i] = 0;
        }
        int psz = p.size();
        for(int i=0;i<psz;i++){
            pcnt[p[i]-'a']++;
        }
        for(int i=0;i<psz;i++){
            if(i >= s.size())
                break;
            scnt[s[i]-'a']++;
        }
        vector<int> ans;
        if(s.size() < p.size())
            return ans;
        for(int idx=0;idx<=s.size()-p.size();idx++){
            bool isCan = true;
            for(int j=0;j<26;j++){
                if(pcnt[j] != scnt[j]){
                    isCan = false;
                    break;
                }
            }
            if(isCan)
                ans.push_back(idx);
            scnt[s[idx]-'a']--;
            if(idx+p.size() < s.size())
                scnt[s[idx+p.size()]-'a']++;
        }
        return ans;
    }
};