class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size(), ans = 0;
        unordered_map<int,int> um, un; //un - prev occurence - index of that character
        while (i < n) {
            um[s[i]]++;
            if (um[s[i]] == 2) {
                while (j < un[s[i]]) {
                    um[s[j]] = 0;
                    j++;
                }
                um[s[i]] = 1; j++;
            }
            ans = max(ans,i-j+1);
            un[s[i]] = i;
            i++;
        }
        return ans;
    }
};
