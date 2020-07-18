class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses,vector<int>(numCourses,0));
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]][prerequisites[i][0]] = 1;
            indegree[prerequisites[i][0]]++;
        }
        
        vector<int> ans;
        vector<bool> visited(numCourses,false);
        for(int start = 0;start<numCourses;start++){
            if(!visited[start]&&indegree[start] == 0){
                queue<int> q;
                q.push(start);
                visited[start] = true;
                while(!q.empty()){
                    int fr = q.front();
                    q.pop();
                    ans.push_back(fr);
                    cout << fr << endl;
                    for(int i=0;i<numCourses;i++){
                        if(adj[fr][i] == 1){
                            indegree[i]--;
                            if(indegree[i] == 0){
                                q.push(i);
                                visited[i] = true;
                            }
                        }
                    }
                }
            }
        }
        if(ans.size() < numCourses){
            vector<int> tmp;
            return tmp;
        }else{
            return ans;
        }
    }
};