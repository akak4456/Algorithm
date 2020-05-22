class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(int i=0;i<s.size();i++){
            map<char,int>::iterator it = m.find(s[i]);
            if(it == m.end()){
                m.insert(make_pair(s[i],1));
            }else{
                it->second++;
            }
        }
        vector<pair<int,char> > vec;
        for(map<char,int>::iterator it = m.begin();it !=m.end();it++){
            vec.push_back(make_pair(-it->second,it->first));
        }
        sort(vec.begin(),vec.end());
        string ret = "";
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<-vec[i].first;j++){
                ret += vec[i].second;
            }
        }
        return ret;
    }
};