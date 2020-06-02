class Solution {
public:
    int cnt = 0;
    bool visited[50000];
    vector<int> adj[50000];
    void dfs(int here){
        visited[here] = true;
        for(int i=0;i<adj[here].size();i++){
            int there = adj[here][i];
            if(!visited[there]){
                cnt++;
                dfs(there);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i=0;i<50000;i++)
            visited[i] = false;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i])
                dfs(i);
        }
        return cnt;
    }
};