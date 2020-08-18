const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        int maxDay = 0;
        while(!q.empty()){
            int y = q.front().first.first;
            int x = q.front().first.second;
            int day = q.front().second;
            
            q.pop();
            maxDay = max(maxDay,day);
            for(int i=0;i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny < 0 || ny >= grid.size()||nx < 0 || nx >= grid[0].size())
                    continue;
                if(grid[ny][nx] == 1){
                    grid[ny][nx] = 2;
                    q.push(make_pair(make_pair(ny,nx),day+1));
                }
            }
            //cout << y << ' ' << x << ' ' << day << endl;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return maxDay;
    }
};