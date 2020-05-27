class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int cnt[50000];
        int minIdx[100010];
        int maxIdx[100010];
        for(int i=0;i<50000;i++){
            cnt[i] = 0;
        }
        for(int i=0;i<100010;i++){
            minIdx[i] = 987654321;
            maxIdx[i] = -1;
        }
        for(int i=0;i<nums.size();i++){
            if(i > 0)
                cnt[i] = cnt[i-1];
            if(nums[i] == 0)
                cnt[i]++;
            else
                cnt[i]--;
        }
        for(int i=0;i<nums.size();i++){
            minIdx[cnt[i]+50000] = min(minIdx[cnt[i]+50000],i);
            maxIdx[cnt[i]+50000] = max(maxIdx[cnt[i]+50000],i);
        }
        int ans = -1;
        for(int i=0;i<100010;i++){
            //cout << maxIdx[i] << ' ' << minIdx[i] << endl;
            if(i == 50000)
                ans = max(ans,maxIdx[i]+1);
            else if(maxIdx[i] != -1)
                ans = max(ans,maxIdx[i]-minIdx[i]);
        }
        return ans;
    }
};