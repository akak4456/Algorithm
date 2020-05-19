//result:오답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <map>
#include <cstdint> //or <stdint.h>
#include <limits>
#include <set>
using namespace std;
vector<vector<int> > adj;
vector<int> discovered;
vector<bool> isCutVertex;
int counter = 0;
int findCutVertex(int here, bool isRoot) {
    discovered[here] = counter++;
    int ret = discovered[here];
    int children = 0;
    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if (discovered[there] == -1) {
            children++;
            int subtree = findCutVertex(there, false);
            if (!isRoot && subtree >= discovered[here])
                isCutVertex[here] = true;
            ret = min(ret, subtree);
        }
        else
            ret = min(ret, discovered[there]);
    }
    if (isRoot) isCutVertex[here] = (children >= 2);
    return ret;
}
/*
vector<int> sccId;
vector<int> discovered;
stack<int> st;
int sccCounter, vertexCounter;
int scc(int here) {
    int ret = discovered[here] = vertexCounter++;
    st.push(here);
    for (int i = 0; i < adj[here].size(); i++) {
        int there = adj[here][i];
        if (discovered[there] == -1)
            ret = min(ret, scc(there));
        else if (sccId[there] == -1) {
            ret = min(ret, discovered[there]);
        }
    }
    if (ret == discovered[here]) {
        while (true) {
            int t = st.top();
            st.pop();
            sccId[t] = sccCounter;
            if (t == here) break;
        }
        sccCounter++;
    }
    return ret;
}
vector<int> tarjanSCC() {
    sccId = discovered = vector<int>(adj.size(), -1);
    sccCounter = vertexCounter = 0;
    for (int i = 0; i < adj.size(); i++) if (discovered[i] == -1) scc(i);
    return sccId;
}
*/
int G, H;
void makeGraph(const vector<pair<int,int> > input) {
    adj = vector<vector<int> >(G);
    for (int i = 0; i < input.size(); i++) {
        int from = input[i].first;
        int to = input[i].second;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
}
vector<bool> isPut;
int solve() {
    discovered = vector<int>(G, -1);
    isCutVertex = vector<bool>(G, false);
    counter = 0;
    findCutVertex(0, true);
    isPut = vector<bool>(G, false);
    //절단점에서 부터 카메라 두기
    int cnt = 0;
    for (int i = 0; i < G; i++) {
        if (isCutVertex[i]) {
            cnt++;
            isPut[i] = true;
            for (int t = 0; t < adj[i].size(); t++) {
                int there = adj[i][t];
                isPut[there] = true;
            }
        }
    }
    for (int i = 0; i < G; i++) {
        if (isPut[i] == false) {
            cnt++;
            isPut[i] = true;
            for (int t = 0; t < adj[i].size(); t++) {
                int there = adj[i][t];
                isPut[there] = true;
            }
        }
    }
    return cnt;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        cin >> G >> H;
        vector<pair<int, int> >input(H);
        for (int i = 0; i < H; i++)
            cin >> input[i].first >> input[i].second;
        makeGraph(input);
        cout << solve() << '\n';
    }
}