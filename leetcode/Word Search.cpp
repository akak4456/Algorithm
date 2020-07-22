class Solution {
public:
    bool dfs(vector<vector<char>>& board,int y,int x,string& word,int idx){
        char tmp = board[y][x];
        board[y][x] = '#';
        if(idx == word.size())
            return true;
        int dy[4] = {-1,0,1,0};
        int dx[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            if(y+dy[i] < 0 || y+dy[i] >= board.size() || x+dx[i] < 0 || x+dx[i] >= board[0].size())
                continue;
            if(word[idx] == board[y+dy[i]][x+dx[i]]){
                if(dfs(board,y+dy[i],x+dx[i],word,idx+1)){
                    return true;
                }
            }
        }
        board[y][x] = tmp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int y=0;y<board.size();y++){
            for(int x=0;x<board[0].size();x++){
                if(board[y][x] == word[0]){
                    if(dfs(board,y,x,word,1))
                        return true;
                }
            }
        }
        return false;
    }
};