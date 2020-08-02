class MyHashSet {
public:
    //1069
    /** Initialize your data structure here. */
    vector<int> arr[1069];
    int hash(int x){
        return x%1069;
    }
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(!contains(key))
            arr[hash(key)].push_back(key);
    }
    
    void remove(int key) {
        if(contains(key)){
            for(int i=0;i<arr[hash(key)].size();i++){
                if(key == arr[hash(key)][i]){
                    arr[hash(key)].erase(arr[hash(key)].begin()+i);
                    break;
                }
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        for(int i=0;i<arr[hash(key)].size();i++){
                if(key == arr[hash(key)][i]){
                    return true;
                }
            }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */