class RandomizedSet {
public:
    int cnt = 0;
    vector<int> hashList[10000];
    /** Initialize your data structure here. */
    int hash(int x){
        if(x < 0)
            x = -x;
        return x % 10000;
    }
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        int head = hash(val);
        for(int i=0;i<hashList[head].size();i++){
            if(hashList[head][i] == val)
                return false;
        }
        cnt++;
        hashList[head].push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int head = hash(val);
        for(int i=0;i<hashList[head].size();i++){
            if(hashList[head][i] == val){
                cnt--;
                hashList[head].erase(hashList[head].begin()+i);
                return true;
            }
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randVal = rand()%cnt + 1;
        int sz = 0;
        int head;
       // cout << "randVal:" << randVal << endl;
        for(head = 0;head<10000;head++){
            sz += hashList[head].size();
         //   cout << "sz:"<<sz << ' ' << "head" << ' ' << head << endl;
            if(randVal <= sz){
                int idx = hashList[head].size()-1;
               // cout << "idx:"<<idx << endl;
                while(randVal < sz){
                    idx--;
                    sz--;
                }
                //cout << idx << endl;
                return hashList[head][idx];
            }
        }
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */