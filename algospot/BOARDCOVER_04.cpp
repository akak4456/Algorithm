//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int boardCover[4][3][2] = { {{0,0},{1,0},{0,1}},{{0,0},{0,1},{-1,1}},{{0,0},{1,0},{1,1}},{{0,0},{0,1},{1,1}} };
//int boardCover[4][3][2] = { {{0,0},{0,-1},{1,-1}},{{0,0},{-1,0},{0,-1}},{{0,0},{0,-1},{-1,-1}},{{0,0},{-1,0},{-1,-1}} };
char board[20][20];
int H, W;
void showBoard(){
    for (int i = 0;i < H;i++) {
        for (int j = 0;j < W;j++)
            cout << board[i][j];
        cout << endl;
    }
    cout << endl;
}
int solve(int startIdx) {
    int idx;
 //  showBoard();
    for (idx = startIdx;idx < H * W;idx++) {
        int y = idx / W;
        int x = idx % W;
        if (board[y][x] == '.')
            break;
    }
  // cout << idx << endl;
    if (idx == H * W) {
        for (int y = 0;y < H;y++) {
            for (int x = 0;x < W;x++) {
                if (board[y][x] == '.')
                    return 0;
            }
        }
        return 1;
    }
    int ret = 0;
    for (int i = 0;i < 4;i++) {
        bool canDo = true;
        for (int j = 0;j < 3;j++) {
            int x = idx % W;
            int y = idx / W;
            int nx = x+boardCover[i][j][0];
            int ny = y+boardCover[i][j][1];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H||board[ny][nx] == '#') {
                canDo = false;
                break;
            }
        }
        if (canDo) {
            for (int j = 0;j < 3;j++) {
                int x = idx % W;
                int y = idx / W;
                int nx = x + boardCover[i][j][0];
                int ny = y + boardCover[i][j][1];
                board[ny][nx] = '#';
            }
            ret += solve(idx+1);
            for (int j = 0;j < 3;j++) {
                int x = idx % W;
                int y = idx / W;
                int nx = x + boardCover[i][j][0];
                int ny = y + boardCover[i][j][1];
                board[ny][nx] = '.';
            }
        }
    }
/*
board[idx/W][idx%W] = '#';
solve(idx+1);
board[idx/W][idx%W] = '.';
은 불필요한 작업이다.
이 알고리즘에 따르면 .을
맨 위 맨 왼쪽 부터 차례로 채워나가게 되는데
이것을 재귀적으로 반복하게 된다.
근데 재귀적으로 반복을 했는데 .을 채우지 못한다면
다음의 .에다가 무엇을 하는 것은 무의미하다.
따라서 불필요한 논리이다.
*/
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
        cin >> H >> W;
        for (int i = 0;i < H;i++)
            for (int j = 0;j < W;j++)
                cin >> board[i][j];
        cout << solve(0) << '\n';
    }
}