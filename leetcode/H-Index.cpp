class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        for(int i=0;i<citations.size();i++){
          //  cout << citations[i] << endl;
        }
        for(int h=citations.size();h>=1;h--){
            //cout << h << endl;
            if(citations[citations.size()-h] < h)
                continue;
            if(h < citations.size() && citations[citations.size()-h-1] > h)
                continue;
            return h;
        }
        return 0;
    }
};