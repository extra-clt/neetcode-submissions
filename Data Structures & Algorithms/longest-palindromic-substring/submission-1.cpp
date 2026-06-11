class Solution {
public:
    //brute force:palindrome function o(n) * o(n2) (consider every string possibilities)
    //one idea is take an element and see if right equals left
    //if i knw a seq is palindrome-if i add one -then not palindrome
    //does stack work - not sure how
    //is there a subproblem overlapping?
    //if i get centre of a palindrome then it looks like one- o(n2)
    string longestPalindrome(string s) {
        int maxLen = -1, idx = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            int iter = min(n-i-1,i), len_iter=1; //centre = i;
            for (int k = 1; k <= iter; k++) {
                if (s[i-k] == s[i+k]) len_iter += 2;
                else break;
            }
            if (len_iter > maxLen) {
                maxLen = len_iter;
                idx = i;
            }
            //same letter - centre = [i,i+1]
            if (i < n-1 && s[i] == s[i+1]) {
                iter = min(n-i-2,i); len_iter=2;
                for (int k = 1; k <= iter; k++) {
                    if (s[i-k] == s[i+1+k]) len_iter += 2;
                    else break;
                }
                if (len_iter > maxLen) {
                    maxLen = len_iter;
                    idx = i;
                }
            }
        }
        int start = idx - (maxLen/2) + 1;
        cout << idx << endl;
        if (maxLen & 1) start = idx - ((maxLen - 1)/2);
        cout << start;
        string ans = "";
        for (int i = start; i < start+maxLen; i++) ans += s[i];
        return ans;
    }
};
