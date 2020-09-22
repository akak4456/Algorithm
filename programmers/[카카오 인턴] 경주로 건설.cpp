#include <string>
#include <cstring>
#include <vector>

using namespace std;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
int dp[25][25][4];
vector<vector<int>> BOARD;
int solve(int x,int y,int dir){
    if(x == BOARD.size()-1 && y == BOARD.size()-1){
        return 0;
    }
    int& ret = dp[x][y][dir];
    if(ret != -1) return ret;
    ret = 987654321;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx < 0 || nx >= BOARD.size() || ny < 0 || ny >= BOARD.size() || BOARD[ny][nx] == 1){
            continue;
        }
        if(dir == i){
            ret = min(ret,solve(nx,ny,i)+100);
        }else{
            ret = min(ret,solve(nx,ny,i)+600);
        }
    }
    return ret;
}
//dir:0-북,1-동,2-남,3-서
int solution(vector<vector<int>> board) {
    memset(dp,-1,sizeof(dp));
    BOARD = board;
    return min(solve(0,0,1),solve(0,0,2));
}