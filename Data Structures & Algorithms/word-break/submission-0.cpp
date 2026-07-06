class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        unordered_map<string,int> um;
        for (string word : wordDict) um[word]++;
        dp[0] = true;
        int n = s.size();
        for (int i = 1; i <= n; i++) {
            if (dp[i-1]) {
                for (int end = i-1; end < n; end++) {
                    string word = s.substr(i-1,end-i+2);
                    if (um.count(word)) dp[end+1] = true;
                }
            }
        }
        return dp[n];
    }
};
