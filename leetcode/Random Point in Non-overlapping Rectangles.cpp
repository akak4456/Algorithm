class Solution {
public:
    vector <int> area;
    vector<vector<int>> src;
    int sum;
    Solution(vector<vector<int>>& rects) {
        src = rects;
        sum = 0;
          for(int i =0 ; i < rects.size(); i++){
             int x1 = rects[i][0];
             int y1 = rects[i][1];
             int x2 = rects[i][2];
             int y2 = rects[i][3];
             int temp = (abs(x2 - x1) + 1) * (abs(y2 - y1) + 1);
             sum += temp;
             area.push_back(sum);
          }
    }
    
    vector<int> pick() {
        int randArea = rand() % sum + 1;
      int i;
      for(i = 0; i < area.size(); i++){
         if(randArea <= area[i]) break;
      }
        
        int rectNum = i;
        vector<int> ret;
        int dx = src[rectNum][2] - src[rectNum][0];
        int dy = src[rectNum][3] - src[rectNum][1];
        ret.push_back(rand()%(dx+1)+src[rectNum][0]);
        ret.push_back(rand()%(dy+1)+src[rectNum][1]);
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */