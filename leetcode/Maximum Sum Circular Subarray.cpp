class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int ret = -1000000000;
        int currentMax = -1000000000;
        for(int i=0;i<A.size();i++){
            currentMax = max(currentMax,0)+A[i];
            ret = max(ret,currentMax);
        }
        cout << "RET:" << ret << endl;
        vector<int> reverseA(A.size(),0);
        for(int i=0;i<A.size();i++)
            reverseA[i] = -A[i];
        int sum = 0;
        for(int i=1;i<A.size()-1;i++){
            sum += A[i];
        }
        currentMax = -1000000000;
        int totalMax = -1000000000;
        for(int i=1;i<reverseA.size()-1;i++){
            currentMax = max(currentMax,0)+reverseA[i];
            totalMax = max(totalMax,currentMax);
        }
        cout << totalMax << endl;
        ret = max(ret,sum+totalMax+A[0]+A.back());
        return ret;
    }
};