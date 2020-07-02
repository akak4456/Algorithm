class Solution {
public:
    int fac[10];
    int setCnt(int bitset){
        int ret = 0;
        for(int i=0;i<10;i++){
            if((bitset & (1<<i)) > 0)
                ret++;
        }
        return ret;
    }
    string solve(int bitset,int k){
        string ret = "";
        int cnt = setCnt(bitset);
       // cout << cnt << endl;
        if(cnt == 0)
            return ret;
        for(int i=0;i<10;i++){
            if((bitset & (1<<i)) > 0){
                // cout << i+1 << ' ' << k  << ' ' << fac[cnt-1]<< endl;
                if(k <= fac[cnt-1]){
                   
                    int newbitset = bitset;
                    newbitset &= ~(1<<i);
                   // cout << to_string(1+i) << endl;
                    ret = to_string(1+i)+solve(newbitset,k);
                    break;
                }else{
                    k -= fac[cnt-1];
                }
            }
        }
        return ret;
    }
    string getPermutation(int n, int k) {
        fac[0] = 1;
        fac[1] = 1;
        for(int i=2;i<10;i++){
            fac[i] = fac[i-1];
            fac[i] *= i;
        }
        return solve((1<<n)-1,k);
    }
};