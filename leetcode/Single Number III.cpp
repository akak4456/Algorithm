class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor0 = 0;
        
        for(int num:nums) 
            xor0^=num; 
        
        int idx = 0;
        for(int i=0; i < 32 ; i ++){	
            if(((xor0>>i) & 1) == 1 ){	
                idx = i;
                break;
            }	
        }
        int xor1 = 0;
        int xor2 = 0;
        for(int num: nums){
            if(((num >> idx) &1) == 1){	
                xor1 ^= num;	
            }else{				
                xor2 ^= num;		
            }					
        }					
        vector<int> result;
        result.push_back(xor1);
        result.push_back(xor2);
        return result;
    }
};