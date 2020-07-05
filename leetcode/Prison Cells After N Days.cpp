class Solution {
public:
    int graph[64];
    void dfs(int start,int here,vector<int>& route){
       // cout <<start<< ' ' << here << endl;
        if(here == graph[here]){
            route.push_back(here);
            return;
        }
       if(start == here){
           return;
       }
        route.push_back(here);
        dfs(start,graph[here],route);
    }
    vector<int> transform(int num){
        vector<int> ret;
        ret.push_back(0);
        for(int i=0;i<6;i++){
            ret.push_back(num%2);
            num/=2;
        }
        ret.push_back(0);
        reverse(ret.begin(),ret.end());
        return ret;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        for(int i=0;i<64;i++){
            vector<int> before;
            before.push_back(0);
            int num = i;
            for(int j=0;j<6;j++){
                before.push_back(num%2);
                num /=2;
            }
            before.push_back(0);
            reverse(before.begin(),before.end());
            vector<int> after = before;
            for(int t=1;t<=6;t++){
                if(before[t-1] == before[t+1]){
                    after[t] = 1;
                }else{
                    after[t] = 0;
                }
            }
            int mul = 1;
            int next = 0;
            for(int t=6;t>=1;t--){
                next += after[t]*mul;
                mul *= 2;
            }
            graph[i] = next;
        }
        if(cells[0] != 0||cells[7] != 0){
            vector<int> after = cells;
            for(int t=1;t<=6;t++){
                if(cells[t-1] == cells[t+1]){
                    after[t] = 1;
                }else{
                    after[t] = 0;
                }
            }
            N--;
            cells = after;
        }
        int next = 0;
        int mul = 1;
        for(int i=6;i>=1;i--){
            next += cells[i]*mul;
            mul*=2;
        }
        vector<int> tmp;
        tmp.push_back(next);
        dfs(next,graph[next],tmp);
      //  tmp.push_back(graph[62]);
       // return tmp;
        if(N == 0){
            return transform(next);
        }else{
            if(N <= tmp.size()-1){
                return transform(tmp[N]);
            }else if(tmp[tmp.size()-1] == tmp[tmp.size()-2]){
                return transform(tmp[tmp.size()-1]);
            }else{
                return transform(tmp[N%tmp.size()]);
            }
        }
        return tmp;
    }
};