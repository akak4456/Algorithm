class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long int> vec;
        vec.push_back(1);
        for(int i=1;i<n;i++){
            long long int minVal = 2123366400;
            for(int j=i-1;j>=0;j--){
                if(vec[j]*2 > vec[i-1]&&vec[j]*2 < minVal){
                    minVal = vec[j]*2;
                }
                if(vec[j]*3 > vec[i-1]&&vec[j]*3 < minVal){
                    minVal = vec[j]*3;
                }
                if(vec[j]*5 > vec[i-1]&&vec[j]*5 < minVal){
                    minVal = vec[j]*5;
                }
            }
            vec.push_back(minVal);
        }
        return vec[vec.size()-1];
    }
};