class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26];
        for(int i=0;i<26;i++)
            cnt[i] = 0;
        for(int i=0;i<tasks.size();i++){
            cnt[tasks[i]-'A']++;
        }
        sort(cnt,cnt+26);
        int maxVal = cnt[25]-1;
        int idle_slots = maxVal*n;
        for(int i=24;i>=0;i--){
            idle_slots -= min(cnt[i],maxVal);
        }
        return idle_slots > 0 ? idle_slots+tasks.size():tasks.size();
    }
};