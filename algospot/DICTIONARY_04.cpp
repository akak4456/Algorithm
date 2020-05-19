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
const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
vector<vector<int> > graph;
int N;
vector<string> input;
bool visited[26];
bool finished[26];
stack<int> st;
int in[26];
bool dfs(int here) {
   // cout <<"here " << (char)(here +  'a') << endl;
    visited[here] = true;
    bool ret = true;
    for (int i = 0; i < graph[here].size(); i++) {
        int there = graph[here][i];
        if (!visited[there]) {
            ret = ret & dfs(there);
        }
        else if (!finished[there]) {
            return false;
        }
    }
    st.push(here);
    finished[here] = true;
    return ret;
}
string ans = "";
bool dfsAll() {
    ans = "";
    bool ret = false;
    for (int i = 0; i < 26; i++) {
      //  cout << graph[i].size()  << ' '<<in[i] << endl;
        if (graph[i].size() == 0 || in[i] > 0)
            continue;
      //  cout << i << endl;
        if (!visited[i]) {
            if (dfs(i)) {
                ret = true;
            }
            else
                return false;
        }
        while (!st.empty()) {
            ans += (char)(st.top() + 'a');
            st.pop();
        }
    }
    return ret;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        graph.clear();
        input.clear();
        graph.resize(26);
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        memset(in, 0, sizeof(in));
        cin >> N;
        input.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> input[i];
        }
        for (int i = 0; i < N-1; i++) {
            int sz = min(input[i].size(), input[i + 1].size());
            for (int pos = 0; pos < sz; pos++) {
                if (input[i][pos] != input[i + 1][pos]) {
                    graph[input[i][pos] - 'a'].push_back(input[i + 1][pos] - 'a');
                    in[input[i + 1][pos] - 'a']++;
                    break;
                }
            }
        }
        if (!dfsAll()) {
            cout << "INVALID HYPOTHESIS\n";
        }
        else {
            string append = "";
            for (int i = 0; i < 26; i++) {
                bool canAdd = true;
                for (int j = 0; j < ans.size(); j++) {
                    if (ans[j] == ALPHABET[i]) {
                        canAdd = false;
                    }
                }
                if (canAdd) {
                    append += (char)(i + 'a');
                }
            }
            cout << ans + append << '\n';
        }
    }
}