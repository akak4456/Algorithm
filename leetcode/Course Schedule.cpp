class Solution {
public:
    vector<int> adj[100000];
    int indegree[100000];
    bool topologicalSort(int n){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        for(int i=0;i<n;i++){
            if(q.empty())
                return false;
            int here = q.front();
            q.pop();
            for(int i=0;i<adj[here].size();i++){
                int there = adj[here][i];
                indegree[there]--;
                if(indegree[there] == 0){
                    q.push(there);
                }
            }
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            indegree[i] = 0;
        }
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        return topologicalSort(numCourses);
    }
};