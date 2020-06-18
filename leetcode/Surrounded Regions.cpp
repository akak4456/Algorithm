class Solution {
public:
    vector<vector<bool> >visited;
    bool dfs(int y,int x,vector<vector<int> >& graph){
        //cout << y << ' ' << x << endl;
        visited[y][x] = true;
        if(y-1 < 0 || y+1 >=graph.size() || x-1 < 0 || x+1 >= graph[0].size())
            return false;
        bool ret = true;
        if(y-1 >= 0&&!visited[y-1][x]&&graph[y-1][x] == 0){
            if(!dfs(y-1,x,graph)){
                ret = false;
            }
        }
        if(y+1 < graph.size()&&!visited[y+1][x]&&graph[y+1][x] == 0){
            if(!dfs(y+1,x,graph)){
                ret = false;
            }
        }
        if(x-1 >= 0 && !visited[y][x-1]&&graph[y][x-1] == 0){
            if(!dfs(y,x-1,graph)){
                ret = false;
            }
        }
        if(x+1 < graph[0].size()&&!visited[y][x+1]&&graph[y][x+1] == 0){
            if(!dfs(y,x+1,graph)){
                ret = false;
            }
        }
        //cout << ret << endl;
        return ret;
    }
    void dfs2(int y,int x,vector<vector<int> >& graph){
        //cout << y << ' ' << x << endl;
        visited[y][x] = true;
        graph[y][x] = 1;
        if(y-1 >= 0&&!visited[y-1][x]&&graph[y-1][x] == 0){
            dfs2(y-1,x,graph);
        }
        if(y+1 < graph.size()&&!visited[y+1][x]&&graph[y+1][x] == 0){
            dfs2(y+1,x,graph);
        }
        if(x-1 >= 0 && !visited[y][x-1]&&graph[y][x-1] == 0){
            dfs2(y,x-1,graph);
        }
        if(x+1 < graph[0].size()&&!visited[y][x+1]&&graph[y][x+1] == 0){
            dfs2(y,x+1,graph);
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int> > graph;
        for(int i=0;i<board.size();i++){
            vector<int> tmp;
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == 'X'){
                    tmp.push_back(1);
                }else{
                    tmp.push_back(0);
                }
            }
            graph.push_back(tmp);
        }
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                if(graph[i][j] == 0){
                    visited = vector<vector<bool> >(graph.size(),vector<bool>(graph[0].size(),false));
                    if(dfs(i,j,graph)){
                        visited = vector<vector<bool> >(graph.size(),vector<bool>(graph[0].size(),false));
                        dfs2(i,j,graph);
                    }
                }
            }
        }
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                if(graph[i][j] == 1){
                    board[i][j] = 'X';
                }else{
                    board[i][j] = 'O';
                }
            }
        }
    }
};