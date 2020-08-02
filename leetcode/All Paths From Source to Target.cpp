class Solution {
public:
    int N;
    vector<bool> visited;
    vector<vector<int>> result;
    void dfs(vector<vector<int>>& graph,int here,vector<int> route){
        if(here == N-1){
            route.push_back(here);
            result.push_back(route);
            return;
        }
        visited[here] = true;
        route.push_back(here);
        for(int i=0;i<graph[here].size();i++){
            int there = graph[here][i];
            if(!visited[there]){
                dfs(graph,there,route);
            }
        }
        visited[here] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        N = graph.size();
        visited = vector<bool>(N,false);
        vector<int> tmp;
        dfs(graph,0,tmp);
        return result;
    }
};