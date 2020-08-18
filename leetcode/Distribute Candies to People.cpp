class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans = vector<int>(num_people,0);
        int candy = 1;
        int idx = 0;
        while(candies > 0){
            if(candies < candy){
                candy = candies;
                candies = 0;
            }else{
                candies -= candy;
            }
            ans[idx++] += candy++;
            if(idx == num_people)
                idx = 0;
        }
        return ans;
    }
};