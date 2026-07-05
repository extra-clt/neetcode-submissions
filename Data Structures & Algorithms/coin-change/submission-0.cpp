class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1,INT_MAX);
        for (int i = 1; i <= amount; i++) {
            for (int j : coins) {
                if (i == j) dp[i] = 1;
                else if (i-j > 0 && dp[i-j] != INT_MAX) dp[i] = min(dp[i],1+dp[i-j]);
            }
        }
        for (int i : dp) cout << i << " ";
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};
