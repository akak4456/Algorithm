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
vector<vector<int> >adj;
void getEulerCircuit(int here, vector<int>& circuit) {
    for (int there = 0; there < adj.size(); there++) {
        while (adj[here][there] > 0) {
            adj[here][there]--;
            adj[there][here]--;
            getEulerCircuit(there, circuit);
        }
    }
    circuit.push_back(here);
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        int N;
        cin >> N;
        vector<string> input;
        input.resize(N);
        for (int i = 0; i < N; i++)
            cin >> input[i];
        adj = vector<vector<int> >(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j)
                    continue;
                if (input[i].back() == input[j][0]) {
                    adj[i][j]++;
                }
            }
        }
        vector<int> ans;
        getEulerCircuit(0, ans);
        if (ans.size() < N) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            for (int i = 0; i < N; i++) {
                cout << input[ans[ans.size() - i - 1]] << ' ';
            }
            cout << '\n';
        }
    }
}