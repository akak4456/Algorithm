class Solution {
public:
    int a;
    long long int modulus;
    string longestDupSubstring(string S) {
        a = 26;
        modulus = (long long int)pow(2, 32);
        int l = 1, r = S.length()-1;
        string result = "";
        while(l <= r) {
            int mid = l + (r-l) / 2;
            string temp = search(S, mid);
            if(temp != "") {
                result = temp;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
    string search(string S, int L) {
        set<long long int> sethash;
        long long int hash = 0, aL = 1;
        for (int i = 1; i <= L; ++i) aL = (aL * a) % modulus;
        for(int i = 0; i < L; ++i) hash = (hash * a + (S[i]-'a')) % modulus;
        sethash.insert(hash);
        for(int i = 1; i+L-1 < S.length(); i++) {
            int j = i+L-1;
            hash = (hash * a - (S[i-1]-'a') * aL % modulus + modulus) % modulus;
            hash = (hash + (S[j]-'a')) % modulus;
            if(sethash.count(hash)) return S.substr(i, j-i+1);
            sethash.insert(hash);
        }
        return "";
    }
};