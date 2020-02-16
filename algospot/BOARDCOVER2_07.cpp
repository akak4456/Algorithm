//result:런타임 오류
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
int h, w, r, c;
vector<vector<char> > board;
vector<vector<char> > block;
vector<vector<pair<int, int> > > rotations;
vector<vector<char> > rotateBlock(const vector<vector<char> >& origin) {
    int newR = origin[0].size();
    int newC = origin.size();
    vector<vector<char> > ret;
    ret.resize(newR);
    for (int i = 0;i < newR;i++) {
        ret[i].resize(newC);
        for (int j = 0;j < newC;j++) {
            ret[i][newC - j - 1] = origin[j][i];
        }
    }
    return ret;
}
void generateRotation() {
    rotations.resize(4);
    vector<vector<char> >newBlock = block;
    for (int i = 0;i < 4;i++) {
        for (int y = 0;y < newBlock.size();y++) {
            for (int x = 0;x < newBlock[y].size();x++) {
                if (newBlock[y][x] == '#')
                    rotations[i].push_back(make_pair(x, y));
            }
        }
        newBlock = rotateBlock(newBlock);
    }
}
int best;
void showBoard() {
    for (int i = 0;i < h;i++) {
        for (int j = 0;j < w;j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}
int maxHeuristic(const vector<vector<char> >& originBoard, const vector<vector<char> >& originBlock) {
    int cntBoard = 0, cntBlock = 0;
    for (int i = 0;i < originBoard.size();i++) {
        for (int j = 0;j < originBoard[i].size();j++) {
            if (originBoard[i][j] == '.')
                cntBoard++;
        }
    }
    for (int i = 0;i < originBlock.size();i++) {
        for (int j = 0;j < originBlock[i].size();j++) {
            if (originBlock[i][j] == '#')
                cntBlock++;
        }
    }
    return cntBoard / cntBlock + 1;
}
void solve(int startIdx,int cnt) {
  //  cout << best << endl;
 //   showBoard();
 //   cout << endl;
    bool isFinished = true;
    for (;startIdx < h * w;startIdx++) {
        if (board[startIdx / w][startIdx % w] == '.') {
            isFinished = false;
            break;
        }
    }
    if (isFinished) {
        best = max(best, cnt);
        return;
    }
    if (cnt + maxHeuristic(board, block) < best)
        return;
    vector<vector<char> > newBlock = block;
    for (int i = 0;i < 4;i++) {
        bool isCan = true;
        int y = startIdx / w;
        int x = startIdx % w;
        for (int idx = 0;idx < rotations.size();idx++) {
            int nx = rotations[i][idx].first;
            int ny = rotations[i][idx].second;
            if (y + ny < 0 || y + ny >= h || x + nx < 0 || x + nx >= w) {
                isCan = false;
                break;
            }
            // cout << y + ny << ' ' << x + nx << endl;
            if (board[y + ny][x + nx] == '#' && newBlock[ny][nx] == '#') {
                isCan = false;
                break;
            }
        }
        if (isCan) {
            for (int idx = 0;idx < rotations.size();idx++) {
                int nx = rotations[i][idx].first;
                int ny = rotations[i][idx].second;
                if (newBlock[ny][nx] == '#') {
                    board[y + ny][x + nx] = '#';
                }
            }
            solve(startIdx + 1, cnt + 1);
            for (int idx = 0;idx < rotations.size();idx++) {
                int nx = rotations[i][idx].first;
                int ny = rotations[i][idx].second;
                if (newBlock[ny][nx] == '#') {
                    board[y + ny][x + nx] = '.';
                }
            }
        }
        newBlock = rotateBlock(newBlock);
    }
    solve(startIdx + 1, cnt);
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
      //  cout << solveCircular();
        cin >> h >> w >> r >> c;
        board.resize(h);
        for (int i = 0;i < h;i++) {
            board[i].resize(w);
            for (int j = 0;j < w;j++) {
                cin >> board[i][j];
            }
        }
        block.resize(r);
        for (int i = 0;i < r;i++) {
            block[i].resize(c);
            for (int j = 0;j < c;j++) {
                cin >> block[i][j];
            }
        }
        generateRotation();
        best = -1;
        solve(0,0);
        cout << best << '\n';
    }
}