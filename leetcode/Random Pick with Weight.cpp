class Solution {
public:
    double prop[10000];
    int sz;
    Solution(vector<int>& w) {
        for(int i=0;i<10000;i++){
            prop[i] = 0;
        }
        double sum = 0;
        sz = w.size();
        for(int i=0;i<sz;i++){
            sum += w[i];
        }
        for(int i=0;i<sz;i++){
            if(i > 0){
                prop[i] = prop[i-1];
            }
            prop[i] += w[i]/sum;
        }
    }
    
    int pickIndex() {
        double r = ((double) rand() / (RAND_MAX));
        for(int i=0; i < sz;i++){
            //cout << i << ' ' << sz << ' ' <<prop[i] << ' ' << r << endl;
            if(prop[i] > r){
                return i;
            }
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */