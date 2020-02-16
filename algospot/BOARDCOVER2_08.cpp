//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
vector<vector<pair<int, int> > > rotations;
int blockSize;
vector<string> rotate(const vector<string>& arr) {
    vector<string> result(arr[0].size(), string(arr.size(), ' ')); //가로와 세로가 뒤바뀐 vector 생성
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr[0].size(); j++)
            result[j][arr.size() - i - 1] = arr[i][j]; //90도 회전
    return result;
}
void generateRotations(vector<string> block) {
    rotations.clear();
    rotations.resize(4);
    for (int rot = 0;rot < 4;rot++) {
        int originY = -1, originX = -1;
        for (int i = 0;i < block.size();i++) {
            for (int j = 0;j < block[i].size();j++) {
                if (block[i][j] == '#') {
                    if (originY == -1) {
                        originY = i;
                        originX = j;
                    }
                    rotations[rot].push_back(make_pair(i - originY, j - originX));
                }
            
            }
        }
        block = rotate(block);
    }
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
    blockSize = rotations[0].size();
}
int boardH, boardW;
vector<string> board;
int covered[10][10];
int best;
bool set(int y, int x, const vector<pair<int, int> >& block, int delta) {
    
    bool result = true;
    for (int i = 0; i < block.size(); i++){

        //범위 내에 있다면

        if (y + block[i].first >= 0 && y + block[i].first < boardH && x + block[i].second >= 0 && x + block[i].second < boardW){
            covered[y + block[i].first][x + block[i].second] += delta;
            result = result && (covered[y + block[i].first][x + block[i].second] == 1);
        }
        else
            result = false;
    }

    return result;
    /*
    if (delta == 1) {
        for (int i = 0;i < block.size();i++) {
            int ny = y + block[i].first, nx = x + block[i].second;
            if (ny < 0 || ny >= boardH || nx < 0 || nx >= boardW || covered[ny][nx] == 1)
                return false;
        }
    }
    for (int i = 0;i < block.size();i++) {
        int ny = y + block[i].first, nx = x + block[i].second;
        covered[ny][nx] = (delta == 1 ? 1 : 0);
    }
    return true;
    */
}
int blockPrune(int placed){
    int cnt = 0;
    for (int i = 0; i < boardH; i++)
        for (int j = 0; j < boardW; j++)
            cnt += !(covered[i][j]) ? 1 : 0;
    return ((cnt / blockSize) + placed <= best);
}
void search(int placed) {
    if (blockPrune(placed))
        return;
    int y = -1, x = -1;
    for (int i = 0;i < boardH;i++) {
        for (int j = 0;j < boardW;j++) {
            if (covered[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) break;
    }
    if (y == -1) {
        best = max(best, placed);
        return;
    }
    for (int i = 0;i < rotations.size();i++) {
        if (set(y, x, rotations[i], 1))
            search(placed + 1);
        set(y, x, rotations[i], -1);
    }
    covered[y][x] = 1;
    search(placed);
    covered[y][x] = 0;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
        board.clear();
        //  cout << solveCircular();
        int r, c;
        vector<string> block;
        cin >> boardH >> boardW >> r >> c;
        board.resize(boardH);
        for (int i = 0;i < boardH;i++) {
            cin >> board[i];
        }
        block.resize(r);
        for (int i = 0;i < r;i++) {
            cin >> block[i];
        }
        generateRotations(block);
        best = 0;

        //covered 배열 초기화

        for (int i = 0; i < boardH; i++)

            for (int j = 0; j < boardW; j++)

                covered[i][j] = (board[i][j] == '#' ? 1 : 0);

        search(0);
        /*
        best = 0;
        for (int i = 0;i < boardH;i++) {
            for (int j = 0;j < boardW;j++) {
                covered[i][j] = (board[i][j] == '#' ? 1 : 0);
            }
        }
        search(0);
        */
        cout << best << '\n';
    }
}