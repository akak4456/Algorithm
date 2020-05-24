class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> > ret;
        if(A.empty()||B.empty())
            return ret;
        int aEnd = A[0][1];
        int bEnd = B[0][1];
        int aidx = 0,bidx = 0;
        while(aidx < A.size() && bidx < B.size()){
            int start = max(A[aidx][0],B[bidx][0]);
            int end = min(A[aidx][1],B[bidx][1]);
            if(start <= end){
                vector<int> tmp;
                tmp.push_back(start);
                tmp.push_back(end);
                ret.push_back(tmp);
            }
            if(aEnd < bEnd){
                aidx++;
                if(aidx < A.size())
                aEnd = A[aidx][1];
            }else{
                bidx++;
                if(bidx < B.size())
                bEnd = B[bidx][1];
            }
        }
        return ret;
    }
};