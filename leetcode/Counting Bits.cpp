class Solution {
public:
    vector<int> countBits(int num) {
        int p = 2;
        vector<int> ret;
        ret.push_back(0);
        if(num == 0)
            return ret;
        ret.push_back(1);
        int nxt = 0;
        for(int i=2;i<=num;i++){
            if(i%p == 0){
                p *= 2;
                nxt = 0;
            }
            ret.push_back(ret[nxt++]+1);
        }
        return ret;
    }
};