class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0) return false;
 
        int p = (int) (log(num) / log(4));
   if(num==pow(4, p)){
       return true;
   }else{
       return false;
   }
    }
};