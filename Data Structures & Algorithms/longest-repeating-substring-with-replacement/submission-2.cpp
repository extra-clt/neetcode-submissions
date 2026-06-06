class Solution {
public:
    int characterReplacement(string s, int k) {
        int curr = s[0], len = 0, sol = 0, lmt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == curr) len++;
            else if (lmt < k) {
                len++; lmt++;
            }
            else {
                sol = max(len,sol);
                curr = s[i];
                int l = i; 
                lmt = 0;
                len = 0;
                while (l >= 0) {
                    if (s[l] == curr) len++;
                    else if (lmt < k) {
                        len++; lmt++;
                    }
                    else break;
                    l--;
                }
            }
        }
        return max(len,sol);
    }

};

