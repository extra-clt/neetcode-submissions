class Solution {
public:
    bool isPalindrome(string s) {
        string word = "";
        for (char &c : s) {
            if (isalnum(c)) word += tolower(c);
        }
        int n = word.size();
        for (int i = 0; i < n/2; i++) {
            if (word[i] != word[n-1-i]) return false;
        }
        return true;
    }
};
