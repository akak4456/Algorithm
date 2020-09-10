class Solution {
public:
    void parse(const string& version,vector<int>& v){
        int startIdx = 0;
        for(int i=1;i<=version.size();i++){
            if(i==version.size()||version[i] == '.'){
                string tmp = version.substr(startIdx,i-startIdx);
                v.push_back(stoi(tmp));
                startIdx = i+1;
            }
        }
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
        parse(version1,v1);
        parse(version2,v2);
        if(v1.size()==v2.size()){
            for(int i=0;i<v1.size();i++){
                if(v1[i] > v2[i]){
                    return 1;
                }else if(v1[i] < v2[i]){
                    return -1;
                }
            }
        }
        int rever = 1;
        if(v2.size() < v1.size()){
            vector<int> tmp = v1;
            v1 = v2;
            v2 = tmp;
            rever = -1;
        }
        for(int i=0;i<v1.size();i++){
            if(v1[i] > v2[i]){
                return 1*rever;
            }else if(v1[i] < v2[i]){
                return -1*rever;
            }
        }
        for(int i=v1.size();i<v2.size();i++){
            if(v2[i] != 0){
                return -1*rever;
            }
        }
        return 0;
    }
};