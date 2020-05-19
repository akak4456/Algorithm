//result:정답
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
struct OptimizedDisjointSet {
    vector<int> parent, rank,enemy,size;
    OptimizedDisjointSet(int n) :parent(n), rank(n, 0),enemy(n,-1),size(n,1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] == -1 ||u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    int merge(int u, int v) {
        if (u == -1 || v == -1) return max(u, v);
        u = find(u), v = find(v);
        if (u == v) return u;
        if (rank[u] > rank[v]) swap(u, v);
        if (rank[u] == rank[v]) rank[v]++;
        parent[u] = v;
        size[v] += size[u];
        return v;
    }
    bool dis(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
        enemy[a] = b; enemy[b] = a;
        return true;
    }
    bool ack(int u, int v) {
        u = find(u); v = find(v);
        if (enemy[u] == v) return false;
        int a = merge(u, v), b = merge(enemy[u], enemy[v]);
        enemy[a] = b;
        if (b != -1) enemy[b] = a;
        return true;
    }
};
int n, m;
int maxParty(const OptimizedDisjointSet& buf) {
    int ret = 0;
    for (int node = 0; node < n; node++) {
        if (buf.parent[node] == node) {
            int enemy = buf.enemy[node];

            if (enemy > node) continue;

            int mySize = buf.size[node];
            int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);

            ret += max(mySize, enemySize);
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
        cin >> n >> m;
        OptimizedDisjointSet disjointset(n);
        bool isContradicted = false;
        for (int step = 1; step <= m; step++) {
            string str;
            int a, b;
            cin >> str >> a >> b;
            if (!isContradicted && str == "ACK") {
                if (!disjointset.ack(a,b)) {
                    cout << "CONTRADICTION AT " << step << '\n';
                    isContradicted = true;
                }
            }
            else if (!isContradicted && str == "DIS") {
                if (!disjointset.dis(a,b)) {
                    cout << "CONTRADICTION AT " << step << '\n';
                    isContradicted = true;
                }
                
            }
        }
        if (!isContradicted) {
            cout << "MAX PARTY SIZE IS " << maxParty(disjointset) << '\n';
        }
    }
}