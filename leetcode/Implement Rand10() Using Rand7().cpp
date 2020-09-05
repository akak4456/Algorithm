// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int rand1 = rand7();
        while(rand1 == 7){
            rand1 = rand7();
        }
        int rand2 = rand7();
        while(rand2 > 5){
            rand2 = rand7();
        }
        if(rand1 <= 3){
            return rand2;
        }else{
            return rand2+5;
        }
        return -1;
    }
};