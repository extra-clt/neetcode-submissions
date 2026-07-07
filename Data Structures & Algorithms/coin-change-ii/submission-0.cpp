class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        vector<int> dp(amount+1,0);
        for (int i : coins) {
            for (int j = 1; j <= amount; j++) {
                if (i == j) dp[j]++;
                if (j-i>0) dp[j] += dp[j-i];
            }
        }
        return dp[amount];
    }
};
