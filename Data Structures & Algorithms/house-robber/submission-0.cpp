class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i] = max. money till there..(cumulative)
        //either start at index 0 or 1
        //when can i take? if taking increases max val/ profit
        //dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        //[2,9]
        //0 0 
        //i = 0: max(0,0+2) = 2
        //0 2
        //i = 1: max(2,0+9) = 9;
        //only 2 previous states-use prev1, prev2 (first previous and second previous)
        int prev2 = 0, prev1 = 0, sol = 0;
        for (int i : nums) {
            sol = max(prev1,prev2+i);
            prev2 = prev1;
            prev1 = sol;
        }
        return sol;
    }
};
