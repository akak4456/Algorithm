class Solution {
public:
    vector<string> result;
    void solve(int N,int K,string src){
        //cout << src << endl;
        if(src.size() == N){
            if(src[0] == '0' && src.size() > 1){
                
            }else{
            result.push_back(src);
            }
            return;
        }
        if(src.empty()){
            for(int i=0;i<=9;i++){
                solve(N,K,src+(char)(i+'0'));
            }
        }else{
            int last = src[src.size()-1]-'0';
            if(last-K >= 0){
                solve(N,K,src+(char)(last-K+'0'));
            }
            if(last+K <= 9){
                solve(N,K,src+(char)(last+K+'0'));
            }
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ret;
        if(K == 0){
            if(N == 1){
                for(int i=0;i<=9;i++)
                ret.push_back(i);
            }else{
                vector<string> tmp;
                for(int i=1;i<=9;i++){
                    string t = "";
                    for(int j=0;j<N;j++){
                        t += i+'0';
                    }
                    tmp.push_back(t);
                }
                for(int i=0;i<tmp.size();i++){
                    ret.push_back(stoi(tmp[i]));
                }
            }
        }else{
            solve(N,K,"");  
            for(int i=0;i<result.size();i++){
                ret.push_back(stoi(result[i]));
            }
        }
        return ret;
    }
};