class Solution {
public:
    int team[2001];
    int enemy[2001];
    int rank[2001];
    int find(int n){
        if(team[n] == n) return n;
        return team[n] = find(team[n]);
    }
    void merge(int a,int b){
        a = find(a),b=find(b);
        if(a == b)
            return;
        if(rank[a] > rank[b]) swap(a,b);
        
        team[a] = b;
        if(rank[a] == rank[b]) ++rank[b];
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(int i=1;i<=N;i++){
            team[i] = i;
            enemy[i] = -1;
            rank[i] = 1;
        }
        for(int i=0;i<dislikes.size();i++){
            int a = find(dislikes[i][0]);
            int b = find(dislikes[i][1]);
            if(a == b)
                return false;
            if(enemy[a] != -1)
            merge(b,enemy[a]);
            if(enemy[b] != -1)
            merge(a,enemy[b]);
            enemy[a] = b;
            enemy[b] = a;
            
        }
        return true;
    }
};