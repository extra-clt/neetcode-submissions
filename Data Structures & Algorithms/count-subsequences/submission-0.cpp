class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        //if t is empty, result is 1 (remove all elements)
        for (int j = 0; j <= m; j++) dp[0][j] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (t[i-1] == s[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else dp[i][j] = dp[i][j-1];//dont take
            }
        }
        return dp[n][m];
    }
};
