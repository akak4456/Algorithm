class Solution {
public:
    int cnt = 0;
    void dfs(vector<vector<int>>&grid,int y,int x){
        //cout << y << ' ' << x << endl;
        grid[y][x] = 2;
       // cout << "BEFORE:"<<cnt<<endl;
        if(y == 0)
            cnt++;
        if(y == grid.size()-1)
            cnt++;
        if(x == 0)
            cnt++;
        if(x == grid[0].size()-1)
            cnt++;
        if(y-1 >= 0){
            int tmp = grid[y-1][x];
            if(tmp == 0){
                cnt++;
            }else if(tmp == 1){
                dfs(grid,y-1,x);
            }
        }
        if(y+1 < grid.size()){
            int tmp = grid[y+1][x];
            if(tmp == 0){
                cnt++;
            }else if(tmp == 1){
                dfs(grid,y+1,x);
            }
        }
        if(x-1 >= 0){
            int tmp = grid[y][x-1];
            if(tmp == 0){
                cnt++;
            }else if(tmp == 1){
                dfs(grid,y,x-1);
            }
        }
        if(x+1 < grid[0].size()){
            int tmp = grid[y][x+1];
            if(tmp == 0){
                cnt++;
            }else if(tmp == 1){
                dfs(grid,y,x+1);
            }
        }
        //cout << "AFTER:"<<cnt << endl;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int y=0;y<grid.size();y++){
            for(int x=0;x<grid[0].size();x++){
                if(grid[y][x] == 1)
                    dfs(grid,y,x);
            }
        }
        return cnt;
    }
};