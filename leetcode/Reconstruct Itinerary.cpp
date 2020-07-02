class Solution {
public:
    map<string,vector<string> >adj;
    vector<pair<string,string>> candidate;
    stack<string> topo;
    void dfs(string here){
       // cout << here << endl;
        vector<string> tmp;
        if(adj.find(here) != adj.end()){
            tmp = adj.find(here)->second;
        }
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();i++){
            string there = tmp[i];
           // cout << "THERE: "<<there << endl;
            vector<pair<string,string> >::iterator it = find(candidate.begin(),candidate.end(),make_pair(here,there));
            if(it != candidate.end()){
                candidate.erase(it);
                dfs(there);
            }
        }
        topo.push(here);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++){
            string from = tickets[i][0];
            string to = tickets[i][1];
            candidate.push_back(make_pair(from,to));
            map<string,vector<string> >::iterator it = adj.find(from);
            if(it == adj.end()){
                vector<string> tmp;
                tmp.push_back(to);
                adj.insert(make_pair(from,tmp));
            }else{
                it->second.push_back(to);
            }
        }
        dfs("JFK");
        vector<string> ans;
        while(!topo.empty()){
            ans.push_back(topo.top());
            topo.pop();
        }
        return ans;
    }
};