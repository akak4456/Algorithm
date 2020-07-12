class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string re = "";
        for(int i=0;i<32;i++){
            re += (n%2)+'0';
            n/=2;
        }
        uint32_t ret = 0;
        uint32_t mul = 1;
        for(int i=re.size()-1;i>=0;i--){
            ret += (re[i]-'0')*mul;
            mul *= 2;
        }
        return ret;
    }
};