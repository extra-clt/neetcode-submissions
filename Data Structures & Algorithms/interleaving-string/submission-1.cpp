class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (s3.size() != m+n) return false;
        vector<vector<unordered_set<string>>> dp(m+1, vector<unordered_set<string>>(n+1));
        dp[0][0].insert("");
        for (int i = 1; i <= m; i++) {
            string word = s1.substr(0,i);
            dp[i][0].insert(word);
        }
        for (int j = 1; j <= n; j++) {
            string word = s2.substr(0,j);
            dp[0][j].insert(word);
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                unordered_set<string> up = dp[i-1][j];
                unordered_set<string> left = dp[i][j-1];
                for (string s : up) {
                    string ns = s+s1[i-1];
                    int ns_size = ns.size();
                    if (ns == s3.substr(0,ns_size)) dp[i][j].insert(ns);
                }
                for (string s : left) {
                    string ns = s+s2[j-1];
                    int ns_size = ns.size();
                    if (ns == s3.substr(0,ns_size)) dp[i][j].insert(ns);
                }
            }
        }
        if (dp[m][n].count(s3)) return true;
        return false;
    }
};
