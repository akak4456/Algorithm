//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;
 
typedef struct {
    int index, money, max_parent;
    bool can_visit, is_goal;
    set<int> adj;
} Vertex;
 
#define undefined -1
 
vector<Vertex> V;
int num_SCC = 0;
vector<int> SCC;
int getSCC(int cur) {
    static int dfsN = -1;
    static stack<int> st;
 
    st.push(cur);
 
    dfsN++;
    V[cur].index = dfsN;
 
    int lowlink = V[cur].index;
    for (int next : V[cur].adj) {
        if (V[next].index == undefined) lowlink = min(lowlink, getSCC(next));
        else if (SCC[next] == undefined) lowlink = min(lowlink, V[next].index);
    }
 
    if (V[cur].index == lowlink) {
        int top;
        do {
            top = st.top(); st.pop();
            SCC[top] = num_SCC;
        } while (top != cur);
 
        num_SCC++;
    }
 
    return lowlink;
}
 
int main() {
    int VN, EN;
    cin >> VN >> EN;
 
    V = vector<Vertex>(VN, { undefined, 0, undefined, false, false, set<int>() });
    for (int i = 0; i < EN; i++) {
        int from, to;
        cin >> from >> to;
        V[from - 1].adj.insert(to - 1);
    }
 
    for (int i = 0; i < VN; i++) {
        int money;
        cin >> money;
        V[i].money = money;
    }
 
    int S, GN;
    cin >> S >> GN;
    S--;
    for (int i = 0; i < GN; i++) {
        int g;
        cin >> g;
        V[g - 1].is_goal = true;
    }
 
    SCC = vector<int>(VN, undefined);
    for (int i = 0; i < VN; i++) if (SCC[i] == undefined) {
        getSCC(i);
    }
 
    vector<Vertex> newV(num_SCC, { undefined, 0, 0, false, false, set<int>() });
    for (int i = 0; i < VN; i++) {
        newV[SCC[i]].money += V[i].money;
        newV[SCC[i]].is_goal |= V[i].is_goal;
        for (int next : V[i].adj) if (SCC[i] != SCC[next]) newV[SCC[i]].adj.insert(SCC[next]);
    }
    int newS = SCC[S];
    newV[newS].can_visit = true;
 
    int res = 0;
    for (int i = newS; i >= 0; i--) if (newV[i].can_visit) {
        newV[i].money += newV[i].max_parent;
        if (newV[i].is_goal) res = max(res, newV[i].money);
 
        for (int next : newV[i].adj) {
            newV[next].max_parent = max(newV[next].max_parent, newV[i].money);
            newV[next].can_visit = true;
        }
    }
 
    cout << res;
 
    return 0;
}