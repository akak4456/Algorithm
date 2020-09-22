const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
class Solution {
public:
    int goal = 0;
    int startX;
    int startY;
    int goalX;
    int goalY;
    int solve(vector<vector<int>>& grid,int x,int y,int cnt){
        if(x == goalX && y == goalY){
            cout << cnt << endl;
            if(cnt == goal){
                return 1;
            }else{
                return 0;
            }
        }
        int ret = 0;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= grid[0].size()||ny < 0 || ny >= grid.size()||grid[ny][nx] == -1){
                continue;
            }
            int prev = grid[y][x];
            grid[y][x] = -1;
            ret += solve(grid,nx,ny,cnt+1);
            grid[y][x] = prev;
        }
        return ret;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX,startY;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] != -1){
                    goal++;
                    if(grid[i][j] == 1){
                        startX = j;
                        startY = i;
                    }else if(grid[i][j] == 2){
                        goalX = j;
                        goalY = i;
                    }
                }
            }
        }
        return solve(grid,startX,startY,1);
    }
};