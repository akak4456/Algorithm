//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> name;
bool canEat[50][50];//canEat[food][person] person은 food를 먹을 수 있나?
bool canDo[50][50];//canDo[food][person] food이후의 음식을 선택하고자 할 때 person은 먹을 수 있음?
int n, m;
int best;
void solve(bool visited[50], int food,int cnt) {
   // cout << food << ' ' << cnt << endl;
    bool finished = true;
    for (int i = 0;i < n;i++) {
       // cout << visited[i] << ' ';
        if (!visited[i]) {
            finished = false;
            break;
        }
        //cout << visited[i] << ' ';
    }
   // cout << endl;
    if (finished) {
        best = min(best, cnt);
        return;
    }
    if (food >= m)
        return;
    bool newVisited[50];
    for (int i = 0;i < n;i++) {
        if( !(visited[i] || canDo[food][i]))
            return;
    }
    solve(visited, food + 1,cnt);//그냥 안먹는다.
   
    for (int i = 0;i < 50;i++) {
        newVisited[i] = visited[i];
    }
    bool edited = false;
    for (int i = 0;i < n;i++) {
        if (canEat[food][i] && !newVisited[i]) {
            edited = true;
            newVisited[i] = true;
        }
    }
    if(edited)
    solve(newVisited, food + 1,cnt+1);
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int c;
    cin >> c;
    while (c--) {
        name.clear();
        for (int i = 0;i < 50;i++) {
            for (int j = 0;j < 50;j++) {
                canEat[i][j] = false;
            }
        }
        cin >> n >> m;
        for (int i = 0;i < n;i++) {
            string str;
            cin >> str;
            name.push_back(str);
        }
        for (int i = 0;i < m;i++) {
            int t;
            cin >> t;
            while (t--) {
                string str;
                cin >> str;
                int idx = 0;
                for (idx = 0;idx < name.size();idx++) {
                    if (name[idx] == str)
                        break;
                }
                //cout << idx << endl;
                canEat[i][idx] = true;
            }
        }
        for (int i = 0;i < 50;i++) {
            for (int j = 0;j < 50;j++) {
                canDo[i][j] = false;
            }
        }
        for (int i1 = 0;i1 < m;i1++) {
            for (int i2 = i1;i2 < m;i2++) {
                for (int j = 0;j < n;j++) {
                    if (canEat[i2][j]) {
                        canDo[i1][j] = true;
                    }
                }
            }
            
        }
        bool visited[50];
        for (int i = 0;i < 50;i++)
            visited[i] = false;
        best = 987654321;
        solve(visited, 0,0);
        cout << best << '\n';
    }
}