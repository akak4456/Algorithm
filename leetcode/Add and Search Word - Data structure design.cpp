struct Trie{
    Trie* nxt[26] = {nullptr,};
    bool terminated = false;
};
void insert(Trie* root, string word){
   // cout << word << endl;
    if(word.empty()){
        root->terminated = true;
        return;
    }
    int idx = word[0]-'a';
    if(root->nxt[idx] == nullptr){
        root->nxt[idx] = new Trie();
    }
    word.erase(word.begin());
    insert(root->nxt[idx],word);
}
bool contains(Trie* root, string word){
   // cout << word << endl;
    if(word.empty()){
        return root->terminated;
    }
    if(word[0] == '.'){
        word.erase(word.begin());
        for(int i=0;i<26;i++){
            if(root->nxt[i] != nullptr && contains(root->nxt[i],word)){
                return true;
            }
        }
    }else{
        int idx = word[0] - 'a';
        word.erase(word.begin());
        if(root->nxt[idx] == nullptr)
            return false;
        return contains(root->nxt[idx],word);
    }
    
    return false;
}
class WordDictionary {
public:
    Trie* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(root,word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        return contains(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */