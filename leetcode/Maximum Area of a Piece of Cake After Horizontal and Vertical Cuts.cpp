class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxH = -1;
        int maxV = -1;
        for(int i=0;i<horizontalCuts.size()-1;i++){
            maxH = max(maxH,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        for(int i=0;i<verticalCuts.size()-1;i++){
            maxV = max(maxV,verticalCuts[i+1]-verticalCuts[i]);
        }
        cout << maxH << ' ' << maxV;
        int ret = 0;
        for(int i=0;i<maxV;i++){
            ret += maxH;
            ret %= 1000000007;
        }
        return ret;
    }
};