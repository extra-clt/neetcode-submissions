class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), past = 0;
        vector<vector<int>> dp(n+2, vector<int> (n+2,0));
        for (int i = 2; i < n+2; i++) {
            for (int j = i; j < n+2; j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-2][i-2]+prices[j-2]-prices[i-2]);
            }
        }
        return dp[n+1][n+1];
    }
};
