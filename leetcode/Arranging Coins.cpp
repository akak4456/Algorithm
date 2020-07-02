class Solution {
public:
    int arrangeCoins(int n) {
        int step = 0;
        long long int sum = 0;
        while(true){
            step++;
            sum += step;
            if(sum == n)
                return step;
            if(sum > n)
                return step-1;
        }
    }
};