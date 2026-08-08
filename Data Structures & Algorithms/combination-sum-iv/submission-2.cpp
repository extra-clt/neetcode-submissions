class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long int> dp(target+1,0);
        for (int j = 1; j <= target; j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (dp[j] > INT_MAX) dp[j] = 0;
                if (j == nums[i]) dp[j]++;
                if (j-nums[i] > 0 && dp[j-nums[i]]>0) dp[j] += dp[j-nums[i]];
            }
            //for (int i : dp) cout << i << " ";
            //cout << endl;
        }
        return dp[target];
    }
};