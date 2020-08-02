class Solution {
public:
    int addDigits(int num) {
        int newNum = num;
        while(newNum / 10 > 0){
            int sum = 0;
            int tmp = newNum;
            while(tmp > 0){
                sum += tmp % 10;
                tmp /= 10;
            }
            newNum = sum;
        }
        return newNum;
    }
};