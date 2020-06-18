class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())
            return 0;
        long long int lo = 0,hi = citations.size()-1;
        for(int i=0;i<=50;i++){
            if (lo > hi)
                return 0;
            long long int mid = (lo+hi)/2;
            long long int h = citations.size()-mid;
           // cout << h << endl;
            if(citations[mid] >= h && (mid <= 0 || citations[mid-1] <= h)){
                return h;
            }
            cout << lo<<' '<< mid << ' ' << hi << ' ' << h << endl;
            if(mid > 0 && citations[mid-1] >= h){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return hi;
    }
};