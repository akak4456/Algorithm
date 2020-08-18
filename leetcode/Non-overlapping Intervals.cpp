class Solution {
public:
    static bool cmp(vector <int>& a, vector <int>& b){
      return a[1] < b[1];
   }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> arr =intervals;
         int n = arr.size();
      if(!n)return 0;
      int cnt = 1;
      sort(arr.begin(), arr.end(), cmp);
      int end = arr[0][1];
      for(int i = 1; i < n; i++){
         if(arr[i][0] >= end){
            end = arr[i][1];
            cnt++;
         }
      }
      return n - cnt;
    }
};