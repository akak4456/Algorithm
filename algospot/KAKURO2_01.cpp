//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int getSize(int mask) {
    int ret = 0;
    for (int i = 1;i <= 9;i++) {
        //cout << (mask & (1 << i) )<< endl;
        if ((mask & (1 << i)) != 0)
            ret++;
    }
    return ret;
}
int getSum(int mask) {
    int ret = 0;
    for (int i = 1;i <= 9;i++) {
        if ((mask & (1 << i)) != 0)
            ret += i;
    }
    return ret;
}
int getCandidates(int len, int sum, int known) {
    int allSets = 0;
    for (int set = 0;set < 1024;set += 2) {
        if ((set & known) == known && getSize(set) == len && getSum(set) == sum)
            allSets |= set;
    }
    return allSets & ~known;
}
int candidates[10][46][1024];
void generateCandidates() {
    memset(candidates, 0, sizeof(candidates));
    for (int set = 0;set < 1024; set += 2) {
        int l = getSize(set), s = getSum(set);

        int subset = set;
        while (true) {
            candidates[l][s][subset] |= (set & ~subset);
            if (subset == 0) break;
            subset = (subset - 1) & set;
        }
    }
}
const int MAXN = 100;
int n, color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];
int q, sum[MAXN * MAXN], length[MAXN * MAXN], known[MAXN * MAXN];

void put(int y, int x, int val) {
    for (int h = 0;h < 2;h++) {
        known[hint[y][x][h]] += (1 << val);
    }
    value[y][x] = val;
}
void remove(int y, int x, int val) {
    for (int h = 0;h < 2;h++) {
        known[hint[y][x][h]] -= (1 << val);
    }
    value[y][x] = 0;
}
int getCandHint(int hint) {
    return candidates[length[hint]][sum[hint]][known[hint]];
}
int getCandCoord(int y, int x) {
    return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}
void printSolution() {
    for (int y = 0;y < n;y++) {
        for (int x = 0;x < n;x++) {
            cout << value[y][x] << ' ';
        }
        cout << '\n';
    }
}
bool search() {
    int y = -1, x = -1, minCands = 1023;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (color[i][j] == 1 && value[i][j] == 0) {
                int cands = getCandCoord(i, j);
                //cout << getSize(minCands) << endl;
                if (getSize(minCands) > getSize(cands)) {
                    minCands = cands;
                    y = i, x = j;
                }
            }
        }
    }
   // cout << y << ' ' << x << endl;
    if (minCands == 0) return false;
    if (y == -1) {
        printSolution();
        return true;
    }
    for (int val = 1;val <= 9;val++) {
        if (minCands & (1 << val)) {
            put(y, x, val);
            if (search()) return true;
            remove(y, x, val);
        }
    }
    return false;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
  //  cout << getSize(1023);
    cin >> c;
    while (c--) {
        memset(color, 0, sizeof(color));
        memset(value, 0, sizeof(value));
        memset(hint, 0, sizeof(hint));
        memset(sum, 0, sizeof(sum));
        memset(length, 0, sizeof(length));
        memset(known, 0, sizeof(known));
        cin >> n;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                cin >> color[i][j];
                value[i][j] = 0;
            }
        }
        cin >> q;
        int hintNum = 0;
        for (int t = 0;t < q;t++) {
            int t1, t2, t3, t4;
            cin >> t1 >> t2 >> t3 >> t4;
            int y = t1 - 1, x = t2 - 1;
            if (t3 == 0) {
                //가로힌트
                int ny = y;
                int nx = x + 1;
                while (color[ny][nx] == 1) {
                    length[hintNum]++;
                    hint[ny][nx][0] = hintNum;
                    sum[hintNum] = t4;
                    nx++;
                }
            }
            else {
                //세로힌트
                int ny = y + 1;
                int nx = x;
                while (color[ny][nx] == 1) {
                    length[hintNum]++;
                    hint[ny][nx][1] = hintNum;
                    sum[hintNum] = t4;
                    ny++;
                }
            }
           // cout << length[hintNum] << endl;
            hintNum++;
        }
        generateCandidates();
        search();
    }
}