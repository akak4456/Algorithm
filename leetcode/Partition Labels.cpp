class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ret;
        vector<int> last = vector<int>(26,0);
        for(int i=0;i<S.size();i++){
            int idx = S[i]-'a';
            last[idx] = max(last[idx],i);
        }
        int start = 0;
        int end = 0;
        for(int pos = 0;pos < S.size();pos++){
            cout << end << endl;
            int idx = S[pos] - 'a';
            if(last[idx] > end){
                end = last[idx];
            }
            if(pos == end){
                ret.push_back(end-start+1);
                start = end+1;
            }
        }
        return ret;
    }
};