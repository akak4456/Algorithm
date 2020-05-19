//result:시간초과
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
const int ALPHABETS = 26;
int toNumber(char ch) { return ch - 'a'; }
struct TrieNode {
    TrieNode* children[ALPHABETS];
    int terminal;
    int first;
    TrieNode* fail;
    vector<int> output;
    TrieNode() :terminal(-1),first(-1) {
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (int i = 0; i < ALPHABETS; i++)
            if (children[i])
                delete children[i];
    }
    void insert(const char* key,int id) {
        if (first == -1) first = id;
        if (*key == 0)
            terminal = id;
        else {
            int next = toNumber(*key);
            if (children[next] == NULL)
                children[next] = new TrieNode();
            children[next]->insert(key + 1, id);
        }
    }
    int type(const char* key, int id) {
        if (*key == 0) return 0;
        if (first == id) return 1;
        int next = toNumber(*key);
        return 1 + children[next]->type(key + 1, id);
    }
    TrieNode* find(const char* key) {
        if (*key == 0) return this;
        int next = toNumber(*key);
        if (children[next] == NULL) return NULL;
        return children[next]->find(key + 1);
    }
};
void computeFailFunc(TrieNode* root) {
    queue<TrieNode*> q;
    root->fail = root;
    q.push(root);
    while (!q.empty()) {
        TrieNode* here = q.front();
        q.pop();
        for (int edge = 0; edge < ALPHABETS; edge++) {
            TrieNode* child = here->children[edge];
            if (!child) continue;

            if (here == root)
                child->fail = root;
            else {
                TrieNode* t = here->fail;
                while (t != root && t->children[edge] == NULL)
                    t = t->fail;
                if (t->children[edge]) t = t->children[edge];
                child->fail = t;
            }
            child->output = child->fail->output;
            if (child->terminal != -1)
                child->output.push_back(child->terminal);
            q.push(child);
        }
    }
}
vector<pair<int, int> > ahoCorasick(const string& s, TrieNode* root) {
    vector<pair<int, int> > ret;
    TrieNode* state = root;
    for (int i = 0; i < s.size(); i++) {
        int chr = toNumber(s[i]);
        while (state != root && state->children[chr] == NULL)
            state = state->fail;
        if (state->children[chr]) state = state->children[chr];
        for (int j = 0; j < state->output.size(); j++) {
            ret.push_back(make_pair(i, state->output[j]));
        }
    }
    return ret;
}
int cache[ALPHABETS+1][101];
TrieNode* root;
int N, M;
int solve(string src, int len) {
  //  cout << src << ' ' << ahoCorasick(src, root).size() << endl;
    if (ahoCorasick(src, root).size() > 0) {
        //cout << "0 return \n";
        return 0;
    }
    if (len == N) {
        //cout << "1 return \n";
        return 1;
    }
    int idx;
    if (len == 0) {
        idx = 0;
    }
    else {
        idx = src[len - 1] - 'a';
    }
    //cout << src<< ' '<<idx << ' ' << len << endl;
    int& ret = cache[idx][len];
    ret = 0;
    for (int i = 0; i < ALPHABETS; i++) {
        char ch = 'a' + i;
        ret += solve(src + ch, len + 1);
        ret %= 10007;
    }
   // cout << "ret:" << ret << endl;
    return ret %= 10007;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        memset(cache, -1, sizeof(cache));
        cin >> N >> M;
        root = new TrieNode();
        for (int i = 0; i < M; i++) {
            string str;
            cin >> str;
            root->insert(str.c_str(), i);
        }
        computeFailFunc(root);
        cout << solve("", 0) << '\n';
        delete root;
    }
}