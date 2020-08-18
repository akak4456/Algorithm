class CombinationIterator {
public:
    vector<string> allCombination;
    int idx = 0;
    void makeAll(string src,string target,int used,int cnt,int maxcnt,int startIdx){
        if(cnt == maxcnt){
           // cout << target << endl;
            allCombination.push_back(target);
            return;
        }
        for(int i=startIdx;i<src.size();i++){
            if((used&(1<<i)) == 0){
                makeAll(src,target+src[i],used+(1<<i),cnt+1,maxcnt,i+1);
            }
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        makeAll(characters,"",0,0,combinationLength,0);
    }
    
    string next() {
        return allCombination[idx++];
    }
    
    bool hasNext() {
        return idx < allCombination.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */