class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0,cow = 0;
        vector<bool> secretVisited = vector<bool>(secret.size(),false);
        vector<bool> guessVisited = vector<bool>(guess.size(),false);
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i]){
                secretVisited[i] = true;
                guessVisited[i] = true;
                bull++;
            }
        }
        for(int i=0;i<guess.size();i++){
            for(int j=0;j<secret.size();j++){
                if(i == j)
                    continue;
                if(guess[i] == secret[j]&&!secretVisited[j]&&!guessVisited[i]){
                    secretVisited[j] = true;
                    guessVisited[i] = true;
                    cow++;
                    break;
                }
                
            }
        }
        string ret = "";
        ret += to_string(bull);
        ret += "A";
        ret += to_string(cow);
        ret += "B";
        return ret;
    }
};