class Solution {
public:
    int INF = 987654321;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int> > adj[100];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        queue<pair<int,pair<int,int> > > q;//here cost depth
        int minCost = INF;
        q.push(make_pair(src,make_pair(0,0)));
        while(!q.empty()){
            int here = q.front().first;
            int cost = q.front().second.first;
            int depth = q.front().second.second;
           // cout << here << ' ' << cost << ' ' << depth << endl;
            q.pop();
            if(here == dst)
                    minCost = min(cost,minCost);
            if(depth == K+1){
                continue;
            }
            for(int i=0;i<adj[here].size();i++){
                int there = adj[here][i].first;
                int addcost = adj[here][i].second;
                if(cost + addcost > minCost)
                    continue;
                q.push(make_pair(there,make_pair(cost+addcost,depth+1)));
            }
        }
        if(minCost == INF)
            return -1;
        else
            return minCost;
    }
};