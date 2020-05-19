//result:정답
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int block;
vector<int> moves;
inline int cell(int y, int x) {
    return 1 << (y * 5 + x);
}
void precalc() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            vector<int> cells;
            for (int dy = 0; dy < 2; dy++) {
                for (int dx = 0; dx < 2; dx++) {
                    cells.push_back(cell(y + dy, x + dx));
                }
            }
            int square = cells[0] + cells[1] + cells[2] + cells[3];
            for (int i = 0; i < 4; i++)
                moves.push_back(square - cells[i]);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            moves.push_back(cell(i, j) + cell(i, j + 1));
            moves.push_back(cell(j, i) + cell(j+1, i));
        }
    }
}
char cache[1 << 25];
char play(int board) {
    char& ret = cache[board];
    if (ret != -1) return ret;
    ret = 0;
    for(int i=0;i<moves.size();i++)
        if((moves[i]&board) == 0)
            if (!play(board | moves[i])) {
                ret = 1;
                break;
            }
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    precalc();
    while (test_case--) {
        block = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char c;
                cin >> c;
                if (c == '#') {
                    block += (1 << (i*5+j));
                }
            }
        }
        memset(cache, -1, sizeof(cache));
        if (play(block) == 1) {
            cout << "WINNING\n";
        }
        else {
            cout << "LOSING\n";
        }
    }
}