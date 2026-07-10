class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> um;
        for (char c: s) um[c]++;
        int cnt = 0, oddcnt = 0;
        for (auto it = um.begin(); it != um.end(); ++it) {
            if (it->second % 2 == 0) cnt += it->second;
            else {
                cnt += it->second-1;
                oddcnt++;
            }
        }
        if (oddcnt>0) return ++cnt;
        return cnt;
    }
};