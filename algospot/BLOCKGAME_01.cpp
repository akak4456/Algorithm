//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
vector<int> moves;
char cache[1 << 25];
int cell(int y, int x) {
    return (1<<(y * 5) + x);
}
void precalc() {
    for (int y = 0;y < 4;y++) {
        for (int x = 0;x < 4;x++) {
            vector<int> cells;
            for (int dy = 0;dy < 2;dy++) {
                for (int dx = 0;dx < 2;dx++) {
                    cells.push_back(cell(y + dy, x + dx));
                }
            }
            int square = cells[0] + cells[1] + cells[2] + cells[3];
            for (int i = 0;i < 4;i++) {
                moves.push_back(square - cells[i]);
            }
        }
    }
    for (int y = 0;y < 5;y++) {
        for (int x = 0;x < 4;x++) {
            //가로2칸블록
            moves.push_back(cell(y, x) + cell(y, x + 1));
        }
    }
    for (int y = 0;y < 4;y++) {
        for (int x = 0;x < 5;x++) {
            //세로2칸블록
            moves.push_back(cell(y, x) + cell(y+1, x));
        }
    }
}
char play(int board) {
    char& ret = cache[board];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0;i < moves.size();i++) {
        if ((moves[i] & board) == 0) {
            if (play(board | moves[i]) == 0) {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precalc();
    int c;
    cin >> c;
    while (c--) {
        memset(cache, -1, sizeof(cache));
        int board = 0;
        for (int i = 0;i < 5;i++) {
            for (int j = 0;j < 5;j++) {
                char c;
                cin >> c;
                if (c == '#') {
                    board += cell(i,j);
                }
            }
        }
        if (play(board) == 0) {
            cout << "LOSING\n";
        }
        else {
            cout << "WINNING\n";
        }
    }
}