class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int amount = accumulate(nums.begin(), nums.end(), 0);
        if (target>amount || target < -amount) return 0;
        int len = 2*amount+1;
        vector<int> dp(len,0);
        dp[amount-nums[0]]++;
        dp[amount+nums[0]]++;
        for (int i = 1; i < nums.size(); i++) {
            vector<int> tmp(len,0);
            for (int j = 0; j < len; j++) {
                if (dp[j] > 0) {
                    tmp[j-nums[i]]+=dp[j];
                    tmp[j+nums[i]]+=dp[j];
                }
            }
            dp = tmp;
        }
        return dp[target+amount];
    }
};
