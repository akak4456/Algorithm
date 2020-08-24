struct Trie{
    Trie* nxt[26] = {nullptr, };
    bool terminated = false;
};
class StreamChecker {
public:
    Trie* root;
    Trie* cur;
    vector<char> stream;
    void insertNode(Trie* trie,string word){
        if(word.empty()){
            trie->terminated = true;
            return;
        }
        int idx = word[word.size()-1] - 'a';
        if(trie->nxt[idx] == nullptr){
            trie->nxt[idx] = new Trie();
        }
        word.erase(word.size()-1,1);
        insertNode(trie->nxt[idx],word);
        cur = root;
    }
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for(int i=0;i<words.size();i++){
            insertNode(root,words[i]);
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        if(stream.size() == 1){
            return root->nxt[letter-'a'] != nullptr && root->nxt[letter-'a']->terminated;
        }else{
            cur = root;
            for(int i=stream.size()-1;i>=0;i--){
                int idx = stream[i] - 'a';
                if(cur->nxt[idx] == nullptr){
                    return false;
                }
                cur = cur->nxt[idx];
                if(cur->terminated)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */