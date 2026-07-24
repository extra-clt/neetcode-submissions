class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(), cnt = 0;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] != ' ') {
                cnt++;
                if (i-1>=0 && s[i-1] == ' ') return cnt;
            }
        }
        return cnt;
    }
};